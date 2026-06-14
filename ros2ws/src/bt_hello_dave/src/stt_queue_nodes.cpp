#include "bt_hello_dave/stt_queue_nodes.hpp"
#include "bt_hello_dave/types.hpp"

#include <chrono>

namespace bt_hello_dave
{

// ---------------------------------------------------------------------------
// CheckSttQueueNonEmpty
// ---------------------------------------------------------------------------

CheckSttQueueNonEmpty::CheckSttQueueNonEmpty(
  const std::string & name, const BT::NodeConfig & config)
: BT::ConditionNode(name, config)
{
}

BT::PortsList CheckSttQueueNonEmpty::providedPorts()
{
  return {};
}

BT::NodeStatus CheckSttQueueNonEmpty::tick()
{
  auto queue = config().blackboard->get<SttQueue>("stt_queue");
  return queue.empty() ? BT::NodeStatus::FAILURE : BT::NodeStatus::SUCCESS;
}

// ---------------------------------------------------------------------------
// CheckSttQueueSize
// ---------------------------------------------------------------------------

CheckSttQueueSize::CheckSttQueueSize(
  const std::string & name, const BT::NodeConfig & config)
: BT::ConditionNode(name, config)
{
}

BT::PortsList CheckSttQueueSize::providedPorts()
{
  return {BT::InputPort<int>("min_size")};
}

BT::NodeStatus CheckSttQueueSize::tick()
{
  int min_size = 1;
  getInput("min_size", min_size);

  auto queue = config().blackboard->get<SttQueue>("stt_queue");
  return static_cast<int>(queue.size()) >= min_size
    ? BT::NodeStatus::SUCCESS
    : BT::NodeStatus::FAILURE;
}

// ---------------------------------------------------------------------------
// CheckSttQueueStaleOrFull
// ---------------------------------------------------------------------------

CheckSttQueueStaleOrFull::CheckSttQueueStaleOrFull(
  const std::string & name, const BT::NodeConfig & config)
: BT::ConditionNode(name, config)
{
}

BT::PortsList CheckSttQueueStaleOrFull::providedPorts()
{
  return {};
}

BT::NodeStatus CheckSttQueueStaleOrFull::tick()
{
  auto queue = config().blackboard->get<SttQueue>("stt_queue");
  if (queue.empty()) {
    return BT::NodeStatus::FAILURE;
  }

  bool full = queue.size() >= 2;

  auto age = std::chrono::system_clock::now() - queue.front().local_time;
  bool stale = age > std::chrono::seconds(STALE_SECONDS);

  return (full || stale) ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}

// ---------------------------------------------------------------------------
// RemoveSttEntries
// ---------------------------------------------------------------------------

RemoveSttEntries::RemoveSttEntries(
  const std::string & name, const BT::NodeConfig & config)
: BT::SyncActionNode(name, config)
{
}

BT::PortsList RemoveSttEntries::providedPorts()
{
  return {BT::InputPort<int>("count")};
}

BT::NodeStatus RemoveSttEntries::tick()
{
  int count = 1;
  getInput("count", count);

  auto queue = config().blackboard->get<SttQueue>("stt_queue");
  for (int i = 0; i < count && !queue.empty(); ++i) {
    queue.pop_front();
  }
  config().blackboard->set("stt_queue", queue);

  return BT::NodeStatus::SUCCESS;
}

}  // namespace bt_hello_dave
