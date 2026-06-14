#pragma once

#include <behaviortree_cpp/bt_factory.h>
#include <string>

namespace bt_hello_dave
{

/// SUCCESS if stt_queue is non-empty, FAILURE otherwise.
class CheckSttQueueNonEmpty : public BT::ConditionNode
{
public:
  CheckSttQueueNonEmpty(const std::string & name, const BT::NodeConfig & config);
  static BT::PortsList providedPorts();
  BT::NodeStatus tick() override;
};

/// SUCCESS if stt_queue.size() >= min_size port value, FAILURE otherwise.
class CheckSttQueueSize : public BT::ConditionNode
{
public:
  CheckSttQueueSize(const std::string & name, const BT::NodeConfig & config);
  static BT::PortsList providedPorts();
  BT::NodeStatus tick() override;
};

/// SUCCESS if stt_queue is "full" (size >= 2) OR the oldest entry is
/// older than STALE_SECONDS, indicating an unmatched entry should be
/// discarded. FAILURE if queue empty or neither condition holds.
class CheckSttQueueStaleOrFull : public BT::ConditionNode
{
public:
  CheckSttQueueStaleOrFull(const std::string & name, const BT::NodeConfig & config);
  static BT::PortsList providedPorts();
  BT::NodeStatus tick() override;

private:
  static constexpr int STALE_SECONDS = 3;
};

/// Removes "count" entries from the front of stt_queue (default 1).
/// Always returns SUCCESS.
class RemoveSttEntries : public BT::SyncActionNode
{
public:
  RemoveSttEntries(const std::string & name, const BT::NodeConfig & config);
  static BT::PortsList providedPorts();
  BT::NodeStatus tick() override;
};

}  // namespace bt_hello_dave
