#pragma once

#include <rclcpp/node.hpp>
#include <rclcpp_lifecycle/lifecycle_node.hpp>
#include <behaviortree_cpp/bt_factory.h>
#include <behaviortree_ros2/ros_node_params.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <dave_interfaces/srv/say.hpp>
#include <voskros/srv/set_grammar.hpp>
#include <bt_hello_dave/grammar_store.hpp>
#include <bt_hello_dave/types.hpp>

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
/// Services exposed (all on this lifecycle node):
///   ~/reload_grammar       (std_srvs/Trigger) -- hot-reload grammar YAML
///   ~/force_unmute         (std_srvs/Trigger) -- manually clear @speaking mute
///   ~/get_blackboard_debug (std_srvs/Trigger) -- dump key blackboard state
class HelloDaveLifecycleNode : public rclcpp_lifecycle::LifecycleNode
{
public:
  explicit HelloDaveLifecycleNode(const rclcpp::NodeOptions & options);

  /// Internal plain rclcpp::Node used by ROS-aware BT nodes
  /// (subscribers, service clients). Add this to the executor
  /// alongside this lifecycle node's base interface.
  rclcpp::Node::SharedPtr get_bt_node() const { return bt_node_; }

  CallbackReturn on_configure(const rclcpp_lifecycle::State & state) override;
  CallbackReturn on_activate(const rclcpp_lifecycle::State & state) override;
  CallbackReturn on_deactivate(const rclcpp_lifecycle::State & state) override;
  CallbackReturn on_cleanup(const rclcpp_lifecycle::State & state) override;
  CallbackReturn on_shutdown(const rclcpp_lifecycle::State & state) override;

private:
  void callSetGrammarWithRetries(const std::vector<std::string> & phrases);
  void registerDebugServices();

  rclcpp::Node::SharedPtr bt_node_;
  rclcpp::CallbackGroup::SharedPtr bt_node_client_cb_group_;
  rclcpp::CallbackGroup::SharedPtr debug_service_cb_group_;
  rclcpp::CallbackGroup::SharedPtr tick_timer_cb_group_;

  std::string grammar_yaml_path_;
  std::string bt_xml_path_;

  std::shared_ptr<GrammarStore> grammar_store_;
  std::shared_ptr<BT::BehaviorTreeFactory> factory_;
  BT::Blackboard::Ptr blackboard_;
  BT::Tree tree_;

  rclcpp::TimerBase::SharedPtr tick_timer_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr reload_service_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr force_unmute_service_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr get_blackboard_debug_service_;
  rclcpp::Client<voskros::srv::SetGrammar>::SharedPtr set_grammar_client_;
};

}  // namespace bt_hello_dave
