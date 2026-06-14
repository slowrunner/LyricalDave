#pragma once

#include <behaviortree_ros2/bt_service_node.hpp>
#include <dave_interfaces/srv/say.hpp>
#include <string>

namespace bt_hello_dave
{

/// Calls /say (dave_interfaces/srv/Say) with the given saystring,
/// volume, and anytime flag, all read from input ports.
///
/// Equivalent CLI:
///   ros2 service call /say dave_interfaces/srv/Say \
///     "{saystring: '<text>', volume: <vol>, anytime: <bool>}"
class SayService : public BT::RosServiceNode<dave_interfaces::srv::Say>
{
public:
  SayService(
    const std::string & name,
    const BT::NodeConfig & config,
    const BT::RosNodeParams & params);

  static BT::PortsList providedPorts();

  bool setRequest(typename dave_interfaces::srv::Say::Request::SharedPtr & request) override;

  BT::NodeStatus onResponseReceived(
    const typename dave_interfaces::srv::Say::Response::SharedPtr & response) override;

  BT::NodeStatus onFailure(BT::ServiceNodeErrorCode error) override;
};

}  // namespace bt_hello_dave
