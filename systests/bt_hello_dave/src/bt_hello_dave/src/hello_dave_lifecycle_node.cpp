#include "bt_hello_dave/hello_dave_lifecycle_node.hpp"
#include "bt_hello_dave/register_nodes.hpp"
#include "bt_hello_dave/types.hpp"

#include <chrono>
#include <thread>

namespace bt_hello_dave
{

HelloDaveLifecycleNode::HelloDaveLifecycleNode(const rclcpp::NodeOptions & options)
: rclcpp_lifecycle::LifecycleNode("hello_dave_bt", options)
{
  declare_parameter("grammar_yaml",
    std::string("/home/ubuntu/LyricalDave/ros2ws/params/bt_hello_dave_grammar.yaml"));
  declare_parameter("bt_xml",
    std::string("/home/ubuntu/LyricalDave/ros2ws/params/bt_hello_dave_tree.xml"));
  declare_parameter("heard_log_path",
    std::string("/home/ubuntu/LyricalDave/logs/heard.log"));
  declare_parameter("tick_period_ms", 100);
}

CallbackReturn HelloDaveLifecycleNode::on_configure(const rclcpp_lifecycle::State & /*state*/)
{
  grammar_yaml_path_ = get_parameter("grammar_yaml").as_string();
  bt_xml_path_ = get_parameter("bt_xml").as_string();

  try {
    grammar_store_ = std::make_shared<GrammarStore>(grammar_yaml_path_);
  } catch (const std::exception & e) {
    RCLCPP_ERROR(get_logger(), "Failed to load grammar YAML '%s': %s",
      grammar_yaml_path_.c_str(), e.what());
    return CallbackReturn::FAILURE;
  }

  factory_ = std::make_shared<BT::BehaviorTreeFactory>();
  registerAllNodes(*factory_, shared_from_this());

  blackboard_ = BT::Blackboard::create();
  blackboard_->set("stt_queue", SttQueue{});
  blackboard_->set("sleep_mode", false);
  blackboard_->set("grammar_store", grammar_store_);

  BatteryStateEntry empty_battery;
  empty_battery.valid = false;
  blackboard_->set("battery_state", empty_battery);

  // Hot-reload service: re-reads grammar YAML and re-pushes the STT
  // grammar list, without restarting the BT tree or this node.
  reload_service_ = create_service<std_srvs::srv::Trigger>(
    "~/reload_grammar",
    [this](
      const std::shared_ptr<rmw_request_id_t> /*request_header*/,
      const std::shared_ptr<std_srvs::srv::Trigger::Request> /*request*/,
      std::shared_ptr<std_srvs::srv::Trigger::Response> response)
    {
      try {
        grammar_store_->reload();

        std::vector<std::string> phrases;
        for (const auto & p : grammar_store_->snapshot()["grammar"]["list"]) {
          phrases.push_back(p.as<std::string>());
        }
        callSetGrammarWithRetries(phrases);

        response->success = true;
        response->message = "Grammar reloaded from " + grammar_store_->path();
        RCLCPP_INFO(get_logger(), "%s", response->message.c_str());
      } catch (const std::exception & e) {
        response->success = false;
        response->message = std::string("Reload failed: ") + e.what();
        RCLCPP_ERROR(get_logger(), "%s", response->message.c_str());
      }
    });

  set_grammar_client_ = create_client<voskros::srv::SetGrammar>("/stt/set_grammar");

  RCLCPP_INFO(get_logger(), "Configured. Grammar: %s  Tree: %s",
    grammar_yaml_path_.c_str(), bt_xml_path_.c_str());

  return CallbackReturn::SUCCESS;
}

CallbackReturn HelloDaveLifecycleNode::on_activate(const rclcpp_lifecycle::State & /*state*/)
{
  // Push the initial grammar to voskros. This blocks (with retries)
  // until /stt/set_grammar is available, covering voskros's ~10s
  // startup window.
  std::vector<std::string> phrases;
  for (const auto & p : grammar_store_->snapshot()["grammar"]["list"]) {
    phrases.push_back(p.as<std::string>());
  }
  callSetGrammarWithRetries(phrases);

  try {
    tree_ = factory_->createTreeFromFile(bt_xml_path_, blackboard_);
  } catch (const std::exception & e) {
    RCLCPP_ERROR(get_logger(), "Failed to create tree from '%s': %s",
      bt_xml_path_.c_str(), e.what());
    return CallbackReturn::FAILURE;
  }

  int period_ms = get_parameter("tick_period_ms").as_int();
  tick_timer_ = create_wall_timer(
    std::chrono::milliseconds(period_ms),
    [this]() {
      tree_.tickOnce();
    });

  RCLCPP_INFO(get_logger(), "Activated. Ticking tree every %d ms.", period_ms);
  return CallbackReturn::SUCCESS;
}

CallbackReturn HelloDaveLifecycleNode::on_deactivate(const rclcpp_lifecycle::State & /*state*/)
{
  if (tick_timer_) {
    tick_timer_->cancel();
  }
  RCLCPP_INFO(get_logger(), "Deactivated.");
  return CallbackReturn::SUCCESS;
}

CallbackReturn HelloDaveLifecycleNode::on_cleanup(const rclcpp_lifecycle::State & /*state*/)
{
  tree_.haltTree();
  RCLCPP_INFO(get_logger(), "Cleaned up.");
  return CallbackReturn::SUCCESS;
}

CallbackReturn HelloDaveLifecycleNode::on_shutdown(const rclcpp_lifecycle::State & /*state*/)
{
  if (tick_timer_) {
    tick_timer_->cancel();
  }
  tree_.haltTree();
  RCLCPP_INFO(get_logger(), "Shutdown.");
  return CallbackReturn::SUCCESS;
}

void HelloDaveLifecycleNode::callSetGrammarWithRetries(const std::vector<std::string> & phrases)
{
  auto req = std::make_shared<voskros::srv::SetGrammar::Request>();
  req->list = phrases;

  constexpr int max_attempts = 20;
  for (int attempt = 0; attempt < max_attempts; ++attempt) {
    if (set_grammar_client_->wait_for_service(std::chrono::seconds(1))) {
      auto future = set_grammar_client_->async_send_request(req);
      if (future.wait_for(std::chrono::seconds(2)) == std::future_status::ready) {
        RCLCPP_INFO(get_logger(), "Grammar set successfully (%zu phrases)", phrases.size());
        return;
      }
    }
    RCLCPP_WARN(get_logger(),
      "Waiting for /stt/set_grammar... (attempt %d/%d)", attempt + 1, max_attempts);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

  RCLCPP_ERROR(get_logger(), "Failed to set grammar after %d attempts", max_attempts);
}

}  // namespace bt_hello_dave

// ---------------------------------------------------------------------------
// main
// ---------------------------------------------------------------------------
int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  rclcpp::NodeOptions options;
  auto node = std::make_shared<bt_hello_dave::HelloDaveLifecycleNode>(options);

  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(node->get_node_base_interface());
  executor.spin();

  rclcpp::shutdown();
  return 0;
}
