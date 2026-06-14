#include "bt_hello_dave/delay_seconds_node.hpp"

namespace bt_hello_dave
{

DelaySeconds::DelaySeconds(const std::string & name, const BT::NodeConfig & config)
: BT::StatefulActionNode(name, config)
{
}

BT::PortsList DelaySeconds::providedPorts()
{
  return {BT::InputPort<double>("seconds")};
}

BT::NodeStatus DelaySeconds::onStart()
{
  double secs = 0.0;
  getInput("seconds", secs);

  if (secs <= 0.0) {
    return BT::NodeStatus::SUCCESS;
  }

  deadline_ = std::chrono::steady_clock::now() +
    std::chrono::milliseconds(static_cast<long>(secs * 1000.0));
  return BT::NodeStatus::RUNNING;
}

BT::NodeStatus DelaySeconds::onRunning()
{
  return std::chrono::steady_clock::now() >= deadline_
    ? BT::NodeStatus::SUCCESS
    : BT::NodeStatus::RUNNING;
}

void DelaySeconds::onHalted()
{
  // nothing to clean up
}

}  // namespace bt_hello_dave
