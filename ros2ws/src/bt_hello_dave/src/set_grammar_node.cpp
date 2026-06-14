#include "bt_hello_dave/set_grammar_node.hpp"

#include <sstream>

namespace bt_hello_dave
{

SetGrammar::SetGrammar(
  const std::string & name,
  const BT::NodeConfig & config,
  const BT::RosNodeParams & params)
: BT::RosServiceNode<voskros::srv::SetGrammar>(name, config, params)
{
}

BT::PortsList SetGrammar::providedPorts()
{
  return providedBasicPorts({
    BT::InputPort<std::string>("grammar_list")
  });
}

bool SetGrammar::setRequest(typename voskros::srv::SetGrammar::Request::SharedPtr & request)
{
  std::string list_str;
  if (!getInput("grammar_list", list_str)) {
    if (auto node = node_.lock()) {
      RCLCPP_ERROR(node->get_logger(), "SetGrammar: missing required input [grammar_list]");
    }
    return false;
  }

  std::vector<std::string> phrases;
  std::stringstream ss(list_str);
  std::string item;
  while (std::getline(ss, item, ';')) {
    if (!item.empty()) {
      phrases.push_back(item);
    }
  }
  request->list = phrases;

  return true;
}

BT::NodeStatus SetGrammar::onResponseReceived(
  const typename voskros::srv::SetGrammar::Response::SharedPtr & /*response*/)
{
  if (auto node = node_.lock()) {
    RCLCPP_INFO(node->get_logger(), "Grammar set successfully");
  }
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus SetGrammar::onFailure(BT::ServiceNodeErrorCode error)
{
  if (auto node = node_.lock()) {
    RCLCPP_ERROR(node->get_logger(), "SetGrammar service failed with error: %d", static_cast<int>(error));
  }
  return BT::NodeStatus::FAILURE;
}

}  // namespace bt_hello_dave
