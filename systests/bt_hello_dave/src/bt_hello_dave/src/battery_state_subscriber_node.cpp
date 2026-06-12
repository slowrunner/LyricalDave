#include "bt_hello_dave/battery_state_subscriber_node.hpp"
#include "bt_hello_dave/types.hpp"

namespace bt_hello_dave
{

BatteryStateSubscriber::BatteryStateSubscriber(
  const std::string & name,
  const BT::NodeConfig & config,
  const BT::RosNodeParams & params)
: BT::RosTopicSubNode<dave_interfaces::msg::BatteryState>(name, config, params)
{
}

BT::PortsList BatteryStateSubscriber::providedPorts()
{
  return providedBasicPorts({});
}

BT::NodeStatus BatteryStateSubscriber::onTick(
  const std::shared_ptr<dave_interfaces::msg::BatteryState> & last_msg)
{
  if (!last_msg) {
    // No new message this tick -- not an error, keep the parallel
    // branch alive.
    return BT::NodeStatus::SUCCESS;
  }

  BatteryStateEntry entry;
  entry.voltage   = last_msg->voltage;
  entry.milliamps = last_msg->milliamps;
  entry.watts     = last_msg->watts;
  entry.percent   = last_msg->percent;
  entry.ros_time  = node_->now();
  entry.local_time = std::chrono::system_clock::now();
  entry.valid = true;

  config().blackboard->set("battery_state", entry);

  return BT::NodeStatus::SUCCESS;
}

}  // namespace bt_hello_dave
