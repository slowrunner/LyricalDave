#pragma once

#include <behaviortree_cpp/bt_factory.h>
#include <rclcpp/rclcpp.hpp>

namespace bt_hello_dave
{

/// Registers all custom Hello Dave BT nodes (plain + ROS-aware) with
/// the given factory, using node for any ROS-aware nodes' shared
/// rclcpp::Node.
void registerAllNodes(
  BT::BehaviorTreeFactory & factory,
  const rclcpp::Node::SharedPtr & node);

}  // namespace bt_hello_dave
