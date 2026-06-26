#include "bt_hello_dave/stt_result_subscriber_node.hpp"
#include "bt_hello_dave/types.hpp"

namespace bt_hello_dave
{

SttResultSubscriber::SttResultSubscriber(
  const std::string & name,
  const BT::NodeConfig & config,
  const BT::RosNodeParams & params)
: BT::RosTopicSubNode<std_msgs::msg::String>(name, config, params)
{
}

BT::PortsList SttResultSubscriber::providedPorts()
{
  return providedBasicPorts({});
}

BT::NodeStatus SttResultSubscriber::onTick(
  const std::shared_ptr<std_msgs::msg::String> & last_msg)
{
  if (!last_msg) {
    // No new message this tick -- not an error, keep the parallel
    // branch alive.
    return BT::NodeStatus::SUCCESS;
  }

  SttEntry entry;
  entry.text = last_msg->data;
  entry.local_time = std::chrono::system_clock::now();

  if (auto node = node_.lock()) {
    entry.ros_time = node->now();
    RCLCPP_INFO(node->get_logger(), "stt_result received: '%s'", entry.text.c_str());
  }

  auto queue = config().blackboard->get<SttQueue>("@stt_queue");
  queue.push_back(entry);
  while (queue.size() > MAX_QUEUE_SIZE) {
    queue.pop_front();
  }
  config().blackboard->set("@stt_queue", queue);

  return BT::NodeStatus::SUCCESS;
}

}  // namespace bt_hello_dave
