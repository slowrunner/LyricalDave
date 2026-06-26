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
///
/// NOTE on bt_node_: behaviortree_ros2's RosNodeParams expects an
/// rclcpp::Node::SharedPtr, but rclcpp_lifecycle::LifecycleNode does
/// NOT inherit from rclcpp::Node (they implement the node interfaces
/// independently), so shared_from_this() on this class cannot be used
/// directly for ROS-aware BT nodes. Instead, a small internal plain
/// rclcpp::Node ("hello_dave_bt_internal") is created and passed to
/// registerAllNodes(); it is added to the same EventsCBGExecutor as
/// this lifecycle node (see main() in hello_dave_lifecycle_node.cpp)
/// so its subscriptions/services/clients are actually serviced.
///
/// NOTE on bt_node_client_cb_group_: callSetGrammarWithRetries() runs
/// synchronously inside on_activate(), which is itself a callback
/// dispatched by the executor on bt_node_'s/this node's default
/// callback group. To let the SetGrammar service *response* callback
/// run concurrently with that blocking wait (rather than deadlocking,
/// since a single callback group's callbacks never run in parallel
/// with each other), set_grammar_client_ is created in its own,
/// separate callback group on bt_node_. The executor (EventsCBGExecutor,
/// which supports multiple callback groups/threads) is then free to
/// service that group's callback while on_activate()'s default-group
/// callback is still blocked on the future.
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

  rclcpp::Node::SharedPtr bt_node_;
  rclcpp::CallbackGroup::SharedPtr bt_node_client_cb_group_;

  std::string grammar_yaml_path_;
  std::string bt_xml_path_;

  std::shared_ptr<GrammarStore> grammar_store_;
  std::shared_ptr<BT::BehaviorTreeFactory> factory_;
  BT::Blackboard::Ptr blackboard_;
  BT::Tree tree_;

  rclcpp::TimerBase::SharedPtr tick_timer_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr reload_service_;
  rclcpp::Client<voskros::srv::SetGrammar>::SharedPtr set_grammar_client_;
};

}  // namespace bt_hello_dave

