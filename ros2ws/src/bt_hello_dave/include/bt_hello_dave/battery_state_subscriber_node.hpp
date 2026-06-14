#pragma once

#include <behaviortree_ros2/bt_topic_sub_node.hpp>
#include <dave_interfaces/msg/battery_state.hpp>
#include <string>

namespace bt_hello_dave
{

/// Subscribes to /battery_state (dave_interfaces/BatteryState). Each
/// new message overwrites the "battery_state" blackboard entry
/// (BatteryStateEntry struct) with both ROS time and local wall-clock
/// time recorded.
///
/// Returns SUCCESS every tick (whether or not a new message arrived)
/// so this branch never halts the enclosing KeepRunningUntilFailure.
class BatteryStateSubscriber
  : public BT::RosTopicSubNode<dave_interfaces::msg::BatteryState>
{
public:
  BatteryStateSubscriber(
    const std::string & name,
    const BT::NodeConfig & config,
    const BT::RosNodeParams & params);

  static BT::PortsList providedPorts();

  BT::NodeStatus onTick(
    const std::shared_ptr<dave_interfaces::msg::BatteryState> & last_msg) override;
};

}  // namespace bt_hello_dave
