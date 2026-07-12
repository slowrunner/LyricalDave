#include "bt_hello_dave/say_service_node.hpp"
#include "bt_hello_dave/types.hpp"

namespace bt_hello_dave
{

SayService::SayService(
  const std::string & name,
  const BT::NodeConfig & config,
  const BT::RosNodeParams & params)
: BT::RosServiceNode<dave_interfaces::srv::Say>(name, config, params)
{
}

BT::PortsList SayService::providedPorts()
{
  return providedBasicPorts({
    BT::InputPort<std::string>("saystring"),
    BT::InputPort<int>("volume"),
    BT::InputPort<bool>("anytime")
  });
}

bool SayService::setRequest(typename dave_interfaces::srv::Say::Request::SharedPtr & request)
{
  std::string text;
  int volume = 50;
  bool anytime = false;

  if (!getInput("saystring", text)) {
    if (auto node = node_.lock()) {
      RCLCPP_ERROR(node->get_logger(), "SayService: missing required input [saystring]");
    }
    return false;
  }
  getInput("volume", volume);
  getInput("anytime", anytime);

  request->saystring = text;
  request->volume = static_cast<int8_t>(volume);
  request->anytime = anytime;

  // Mute STT while /say call is in flight (blocking until speech done).
  config().blackboard->set("@speaking", true);
  config().blackboard->set("@speaking_since", std::chrono::steady_clock::now());

  return true;
}

BT::NodeStatus SayService::onResponseReceived(
  const typename dave_interfaces::srv::Say::Response::SharedPtr & response)
{
  // Clear mute. If speech actually played, hold a grace-period pad to
  // absorb mic/room tail. If quiet-time (spoken==false), lift immediately.
  if (response->spoken) {
    config().blackboard->set("@mute_until",
      std::chrono::steady_clock::now() + SPEAKING_GRACE_PERIOD);
  }
  config().blackboard->set("@speaking", false);
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus SayService::onFailure(BT::ServiceNodeErrorCode error)
{
  // Always clear mute on failure so a bad /say call doesn't
  // permanently deafen the system.
  config().blackboard->set("@speaking", false);
  if (auto node = node_.lock()) {
    RCLCPP_ERROR(node->get_logger(), "SayService failed with error: %d", static_cast<int>(error));
  }
  return BT::NodeStatus::FAILURE;
}

}  // namespace bt_hello_dave

