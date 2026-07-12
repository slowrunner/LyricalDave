#include "bt_hello_dave/hello_dave_lifecycle_node.hpp"
#include "bt_hello_dave/register_nodes.hpp"
#include "bt_hello_dave/types.hpp"

#include <chrono>
#include <iomanip>
#include <sstream>
#include <thread>

namespace bt_hello_dave
{

HelloDaveLifecycleNode::HelloDaveLifecycleNode(const rclcpp::NodeOptions & options)
: rclcpp_lifecycle::LifecycleNode("hello_dave_bt", options),
  bt_node_(std::make_shared<rclcpp::Node>(
    "hello_dave_bt_internal",
    rclcpp::NodeOptions().use_global_arguments(false)))
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
  registerAllNodes(*factory_, bt_node_);

  blackboard_ = BT::Blackboard::create();


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

  // set_grammar_client_ is created in its own callback group, separate
  // from bt_node_'s/this node's default callback group, so its
  // service-response callback can be serviced by the executor while
  // callSetGrammarWithRetries() blocks waiting on the future (called
  // from on_activate(), which runs as a default-group callback).
  bt_node_client_cb_group_ = bt_node_->create_callback_group(
    rclcpp::CallbackGroupType::MutuallyExclusive);

  set_grammar_client_ = bt_node_->create_client<voskros::srv::SetGrammar>(
    "/stt/set_grammar",
    rclcpp::ServicesQoS(),
    bt_node_client_cb_group_);

  tick_timer_cb_group_ = create_callback_group(
      rclcpp::CallbackGroupType::MutuallyExclusive);

  // Dedicated callback group for debug/control services so they can
  // always be serviced regardless of what the tick timer is doing.
  debug_service_cb_group_ = create_callback_group(
    rclcpp::CallbackGroupType::Reentrant);

  registerDebugServices();

  RCLCPP_INFO(get_logger(), "Configured. Grammar: %s  Tree: %s",
    grammar_yaml_path_.c_str(), bt_xml_path_.c_str());

  return CallbackReturn::SUCCESS;
}

CallbackReturn HelloDaveLifecycleNode::on_activate(const rclcpp_lifecycle::State & /*state*/)
{
  // Push the initial grammar to voskros. This blocks (with retries)
  // until /stt/set_grammar is available, covering voskros's ~10s
  // startup window. Safe to block here because set_grammar_client_'s
  // response callback runs in a separate callback group serviced
  // concurrently by the EventsCBGExecutor (see main()).
  std::vector<std::string> phrases;
  for (const auto & p : grammar_store_->snapshot()["grammar"]["list"]) {
    phrases.push_back(p.as<std::string>());
  }
  callSetGrammarWithRetries(phrases);

  try {
    tree_ = factory_->createTreeFromFile(bt_xml_path_, blackboard_);

    // Re-initialize blackboard keys on the tree's root blackboard to
    // ensure correct type registration before the first tick.
    auto  root_bb = tree_.rootBlackboard();
    root_bb->set("@stt_queue", SttQueue{});
    root_bb->set("@sleep_mode", false);
    root_bb->set("@grammar_store", grammar_store_);

    BatteryStateEntry empty_battery;
    empty_battery.valid = false;
    root_bb->set("@battery_state", empty_battery);

    // Mute/speaking state -- initialised to "not speaking, not muted"
    root_bb->set("@speaking", false);
    auto epoch = std::chrono::steady_clock::now();
    root_bb->set("@speaking_since", epoch);
    root_bb->set("@mute_until", epoch);



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
    },
    tick_timer_cb_group_);

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

void HelloDaveLifecycleNode::registerDebugServices()
{
  // -----------------------------------------------------------------
  // /hello_dave_bt/force_unmute  (std_srvs/Trigger)
  // Manually clears @speaking and @mute_until so the system can hear
  // again immediately, in case a stuck-mute isn't auto-cleared yet.
  // -----------------------------------------------------------------
  force_unmute_service_ = create_service<std_srvs::srv::Trigger>(
    "~/force_unmute",
    [this](
      const std::shared_ptr<rmw_request_id_t> /*hdr*/,
      const std::shared_ptr<std_srvs::srv::Trigger::Request> /*req*/,
      std::shared_ptr<std_srvs::srv::Trigger::Response> resp)
    {
      if (!blackboard_) {
        resp->success = false;
        resp->message = "Blackboard not yet initialised (tree not active)";
        return;
      }
      auto root_bb = tree_.rootBlackboard();
      auto now = std::chrono::steady_clock::now();
      root_bb->set("@speaking", false);
      root_bb->set("@mute_until", now);
      resp->success = true;
      resp->message = "Mute cleared";
      RCLCPP_INFO(get_logger(), "force_unmute: mute cleared by service call");
    },
    rclcpp::ServicesQoS(),
    debug_service_cb_group_);

  // -----------------------------------------------------------------
  // /hello_dave_bt/get_blackboard_debug  (std_srvs/Trigger)
  // Returns a human-readable snapshot of the key blackboard entries.
  // -----------------------------------------------------------------
  get_blackboard_debug_service_ = create_service<std_srvs::srv::Trigger>(
    "~/get_blackboard_debug",
    [this](
      const std::shared_ptr<rmw_request_id_t> /*hdr*/,
      const std::shared_ptr<std_srvs::srv::Trigger::Request> /*req*/,
      std::shared_ptr<std_srvs::srv::Trigger::Response> resp)
    {
      if (!blackboard_) {
        resp->success = false;
        resp->message = "Blackboard not yet initialised (tree not active)";
        return;
      }

      auto root_bb = tree_.rootBlackboard();
      auto now = std::chrono::steady_clock::now();
      std::ostringstream oss;

      // @speaking
      try {
        bool speaking = root_bb->get<bool>("@speaking");
        oss << "speaking: " << (speaking ? "true" : "false");
        if (speaking) {
          TimePoint since = root_bb->get<TimePoint>("@speaking_since");
          auto age_ms = std::chrono::duration_cast<std::chrono::milliseconds>(now - since).count();
          oss << " (for " << age_ms << " ms)";
        }
      } catch (...) { oss << "speaking: <unavailable>"; }
      oss << "\n";

      // @mute_until
      try {
        TimePoint mute_until = root_bb->get<TimePoint>("@mute_until");
        auto remaining_ms = std::chrono::duration_cast<std::chrono::milliseconds>(mute_until - now).count();
        if (remaining_ms > 0) {
          oss << "mute_until: active (" << remaining_ms << " ms remaining)\n";
        } else {
          oss << "mute_until: expired\n";
        }
      } catch (...) { oss << "mute_until: <unavailable>\n"; }

      // @sleep_mode
      try {
        bool sleep = root_bb->get<bool>("@sleep_mode");
        oss << "sleep_mode: " << (sleep ? "true" : "false") << "\n";
      } catch (...) { oss << "sleep_mode: <unavailable>\n"; }

      // @stt_queue
      try {
        SttQueue q = root_bb->get<SttQueue>("@stt_queue");
        oss << "stt_queue: " << q.size() << " entries";
        for (size_t i = 0; i < q.size(); ++i) {
          oss << "\n  [" << i << "] \"" << q[i].text << "\"";
        }
        oss << "\n";
      } catch (...) { oss << "stt_queue: <unavailable>\n"; }

      // @battery_state
      try {
        BatteryStateEntry bs = root_bb->get<BatteryStateEntry>("@battery_state");
        if (bs.valid) {
          oss << std::fixed << std::setprecision(1);
          oss << "battery: " << bs.voltage << "V  "
              << bs.milliamps << "mA  "
              << bs.watts << "W  "
              << std::lround(bs.percent) << "%\n";
        } else {
          oss << "battery: not yet received\n";
        }
      } catch (...) { oss << "battery: <unavailable>\n"; }

      resp->success = true;
      resp->message = oss.str();
      RCLCPP_INFO(get_logger(), "get_blackboard_debug:\n%s", oss.str().c_str());
    },
    rclcpp::ServicesQoS(),
    debug_service_cb_group_);
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

  // EventsCBGExecutor with 3 threads:
  //   thread 1: BT tick timer callbacks (high frequency, 10Hz)
  //   thread 2: ROS service/subscriber callbacks (STT, battery, say)
  //   thread 3: debug/control services + lifecycle transitions + SIGINT handling


  rclcpp::executors::EventsCBGExecutor executor(rclcpp::ExecutorOptions(), 3);
  executor.add_node(node->get_node_base_interface());
  executor.add_node(node->get_bt_node());
  executor.spin();

  rclcpp::shutdown();
  return 0;
}
