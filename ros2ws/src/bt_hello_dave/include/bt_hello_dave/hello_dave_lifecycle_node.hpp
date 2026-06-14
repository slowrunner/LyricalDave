#pragma once

#include <rclcpp/node.hpp>
#include <rclcpp_lifecycle/lifecycle_node.hpp>
#include <behaviortree_cpp/bt_factory.h>
#include <behaviortree_ros2/ros_node_params.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <voskros/srv/set_grammar.hpp>
#include <bt_hello_dave/grammar_store.hpp>

#include <memory>
#include <string>
#include <vector>

namespace bt_hello_dave
{

using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

/// Lifecycle wrapper around the Hello Dave BT.
///
/// Transitions:
///   configure -> load grammar YAML (GrammarStore), build BT factory,
///                register all custom nodes, create blackboard.
///   activate  -> call /stt/set_grammar with retries (covers voskros
///                startup window), load tree from XML, start tick timer.
///   deactivate -> stop tick timer.
///   cleanup   -> halt tree.
///   shutdown  -> stop timer + halt tree.
///
/// Also exposes /hello_dave/reload_grammar (std_srvs/Trigger) to
/// hot-reload the grammar YAML (fixed responses, random pool, grammar
/// list) without restarting the node. The grammar list portion of a
/// reload re-calls /stt/set_grammar.
class HelloDaveLifecycleNode : public rclcpp_lifecycle::LifecycleNode
{
public:
  explicit HelloDaveLifecycleNode(const rclcpp::NodeOptions & options);

  CallbackReturn on_configure(const rclcpp_lifecycle::State & state) override;
  CallbackReturn on_activate(const rclcpp_lifecycle::State & state) override;
  CallbackReturn on_deactivate(const rclcpp_lifecycle::State & state) override;
  CallbackReturn on_cleanup(const rclcpp_lifecycle::State & state) override;
  CallbackReturn on_shutdown(const rclcpp_lifecycle::State & state) override;

  rclcpp::Node::SharedPtr get_bt_node() const { return bt_node_; }

private:
  void callSetGrammarWithRetries(const std::vector<std::string> & phrases);

  std::string grammar_yaml_path_;
  std::string bt_xml_path_;

  std::shared_ptr<GrammarStore> grammar_store_;
  std::shared_ptr<BT::BehaviorTreeFactory> factory_;
  BT::Blackboard::Ptr blackboard_;
  BT::Tree tree_;

  rclcpp::TimerBase::SharedPtr tick_timer_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr reload_service_;
  rclcpp::Client<voskros::srv::SetGrammar>::SharedPtr set_grammar_client_;

  rclcpp::Node::SharedPtr bt_node_;
};

}  // namespace bt_hello_dave
