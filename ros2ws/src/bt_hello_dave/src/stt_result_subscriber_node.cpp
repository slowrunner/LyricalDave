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
    return BT::NodeStatus::SUCCESS;
  }

  auto now_steady = std::chrono::steady_clock::now();

  // --- Mute check: drop incoming STT while /say is in flight or
  //     within the post-speech grace period, to prevent TTS feedback. ---

  // Auto-clear stuck mute: if @speaking has been true longer than
  // SPEAKING_TIMEOUT_CEILING, force-clear it so the system self-heals.
  bool speaking = false;
  try {
    speaking = config().blackboard->get<bool>("@speaking");
  } catch (...) {}

  if (speaking) {
    TimePoint since;
    try {
      since = config().blackboard->get<TimePoint>("@speaking_since");
    } catch (...) {
      since = now_steady;
    }
    if (now_steady - since > SPEAKING_TIMEOUT_CEILING) {
      if (auto node = node_.lock()) {
        RCLCPP_WARN(node->get_logger(),
          "stt_subscriber: @speaking stuck for >%llds -- auto-clearing mute",
          static_cast<long long>(SPEAKING_TIMEOUT_CEILING.count() / 1000));
      }
      config().blackboard->set("@speaking", false);
      config().blackboard->set("@mute_until", now_steady);
      speaking = false;
    }
  }

  if (speaking) {
    if (auto node = node_.lock()) {
      RCLCPP_INFO(node->get_logger(),
        "stt_subscriber: muted (@speaking) -- dropping: '%s'", last_msg->data.c_str());
    }
    return BT::NodeStatus::SUCCESS;
  }

  // Grace-period check (post-speech tail after speaking=false)
  TimePoint mute_until;
  try {
    mute_until = config().blackboard->get<TimePoint>("@mute_until");
  } catch (...) {
    mute_until = now_steady;
  }

  if (now_steady < mute_until) {
    if (auto node = node_.lock()) {
      RCLCPP_INFO(node->get_logger(),
        "stt_subscriber: muted (grace period) -- dropping: '%s'", last_msg->data.c_str());
    }
    return BT::NodeStatus::SUCCESS;
  }

  // --- Not muted: enqueue the message ---
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
