#pragma once

#include <behaviortree_ros2/bt_topic_sub_node.hpp>
#include <std_msgs/msg/string.hpp>
#include <string>

namespace bt_hello_dave
{

/// Subscribes to /stt/result (std_msgs/String). Each new message is
/// pushed onto the "stt_queue" blackboard entry (capped at 2 entries,
/// oldest dropped) with both ROS time and local wall-clock time
/// recorded.
///
/// Returns SUCCESS every tick (whether or not a new message arrived)
/// so this branch never halts the enclosing KeepRunningUntilFailure.
class SttResultSubscriber : public BT::RosTopicSubNode<std_msgs::msg::String>
{
public:
  SttResultSubscriber(
    const std::string & name,
    const BT::NodeConfig & config,
    const BT::RosNodeParams & params);

  static BT::PortsList providedPorts();

  BT::NodeStatus onTick(const std::shared_ptr<std_msgs::msg::String> & last_msg) override;

private:
  static constexpr size_t MAX_QUEUE_SIZE = 2;
};

}  // namespace bt_hello_dave
