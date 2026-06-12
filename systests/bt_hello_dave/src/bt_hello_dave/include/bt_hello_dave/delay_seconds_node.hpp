#pragma once

#include <behaviortree_cpp/bt_factory.h>
#include <chrono>
#include <string>

namespace bt_hello_dave
{

/// Asynchronous (non-blocking) delay node. Reads "seconds" from an
/// input port (double). If <= 0, returns SUCCESS immediately.
/// Otherwise returns RUNNING until the deadline passes, then SUCCESS.
class DelaySeconds : public BT::StatefulActionNode
{
public:
  DelaySeconds(const std::string & name, const BT::NodeConfig & config);

  static BT::PortsList providedPorts();

  BT::NodeStatus onStart() override;
  BT::NodeStatus onRunning() override;
  void onHalted() override;

private:
  std::chrono::steady_clock::time_point deadline_;
};

}  // namespace bt_hello_dave
