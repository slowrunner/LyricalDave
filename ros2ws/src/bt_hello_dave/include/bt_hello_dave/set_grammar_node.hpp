#pragma once

#include <behaviortree_ros2/bt_service_node.hpp>
#include <voskros/srv/set_grammar.hpp>
#include <string>
#include <vector>

namespace bt_hello_dave
{

/// Calls /stt/set_grammar (voskros/srv/SetGrammar) with a semicolon
/// separated phrase list read from the "grammar_list" input port.
///
/// Equivalent CLI:
///   ros2 service call /stt/set_grammar voskros/srv/SetGrammar \
///     '{list: ["hello dave", "hi dave", ...]}'
class SetGrammar : public BT::RosServiceNode<voskros::srv::SetGrammar>
{
public:
  SetGrammar(
    const std::string & name,
    const BT::NodeConfig & config,
    const BT::RosNodeParams & params);

  static BT::PortsList providedPorts();

  bool setRequest(typename voskros::srv::SetGrammar::Request::SharedPtr & request) override;

  BT::NodeStatus onResponseReceived(
    const typename voskros::srv::SetGrammar::Response::SharedPtr & response) override;

  BT::NodeStatus onFailure(BT::ServiceNodeErrorCode error) override;
};

}  // namespace bt_hello_dave
