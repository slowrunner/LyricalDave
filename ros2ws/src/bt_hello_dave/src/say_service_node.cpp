#include "bt_hello_dave/say_service_node.hpp"

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

  return true;
}

BT::NodeStatus SayService::onResponseReceived(
  const typename dave_interfaces::srv::Say::Response::SharedPtr & /*response*/)
{
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus SayService::onFailure(BT::ServiceNodeErrorCode error)
{
  if (auto node = node_.lock()) {
    RCLCPP_ERROR(node->get_logger(), "SayService failed with error: %d", static_cast<int>(error));
  }
  return BT::NodeStatus::FAILURE;
}

}  // namespace bt_hello_dave
