#include <behaviortree_cpp/bt_factory.h>
#include <behaviortree_ros2/ros_node_params.hpp>

#include "bt_hello_dave/register_nodes.hpp"
#include "bt_hello_dave/match_grammar_node.hpp"
#include "bt_hello_dave/stt_queue_nodes.hpp"
#include "bt_hello_dave/stt_result_subscriber_node.hpp"
#include "bt_hello_dave/battery_state_subscriber_node.hpp"
#include "bt_hello_dave/say_service_node.hpp"
#include "bt_hello_dave/set_grammar_node.hpp"
#include "bt_hello_dave/delay_seconds_node.hpp"
#include "bt_hello_dave/dispatch_nodes.hpp"

namespace bt_hello_dave
{

/// Registers every custom node (plain BT::TreeNode subclasses and
/// ROS-aware nodes) with the given factory. ROS-aware nodes share the
/// given rclcpp node via BT::RosNodeParams, with per-node default
/// topic/service/action names overridable from the BT XML via the
/// usual "topic_name=" / "service_name=" / "action_name=" attributes.
void registerAllNodes(
  BT::BehaviorTreeFactory & factory,
  const rclcpp::Node::SharedPtr & node)
{
  // -- Plain (non-ROS) nodes -------------------------------------------------
  factory.registerNodeType<MatchGrammar>("MatchGrammar");
  factory.registerNodeType<CheckSttQueueNonEmpty>("CheckSttQueueNonEmpty");
  factory.registerNodeType<CheckSttQueueSize>("CheckSttQueueSize");
  factory.registerNodeType<CheckSttQueueStaleOrFull>("CheckSttQueueStaleOrFull");
  factory.registerNodeType<RemoveSttEntries>("RemoveSttEntries");
  factory.registerNodeType<DelaySeconds>("DelaySeconds");
  factory.registerNodeType<LogHeard>("LogHeard");
  factory.registerNodeType<CheckPhraseInList>("CheckPhraseInList");
  factory.registerNodeType<BuildBatteryReport>("BuildBatteryReport");

  // -- ROS topic subscriber nodes -------------------------------------------
  BT::RosNodeParams stt_sub_params;
  stt_sub_params.nh = node;
  stt_sub_params.default_port_value = "/stt/result";
  factory.registerNodeType<SttResultSubscriber>("SttResultSubscriber", stt_sub_params);

  BT::RosNodeParams battery_sub_params;
  battery_sub_params.nh = node;
  battery_sub_params.default_port_value = "/battery_state";
  factory.registerNodeType<BatteryStateSubscriber>("BatteryStateSubscriber", battery_sub_params);

  // -- ROS service client nodes ----------------------------------------------
  BT::RosNodeParams say_params;
  say_params.nh = node;
  say_params.default_port_value = "/say";
  factory.registerNodeType<SayService>("SayService", say_params);
  factory.registerNodeType<SayFixed>("SayFixed", say_params);
  factory.registerNodeType<SayRandomGreeting>("SayRandomGreeting", say_params);

  BT::RosNodeParams set_grammar_params;
  set_grammar_params.nh = node;
  set_grammar_params.default_port_value = "/stt/set_grammar";
  factory.registerNodeType<SetGrammar>("SetGrammar", set_grammar_params);
}

}  // namespace bt_hello_dave
