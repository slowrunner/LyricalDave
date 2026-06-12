#pragma once

#include <behaviortree_cpp/bt_factory.h>
#include <string>

namespace bt_hello_dave
{

/// Matches stt_queue entries against the grammar phrase list.
///
/// Port "window":
///   1 -> checks the newest entry (queue.back()) for an exact
///        substring match against any grammar phrase.
///   2 -> concatenates the two oldest entries (queue[0] + " " + queue[1])
///        in arrival order, to catch phrases split across two
///        /stt/result messages.
///
/// On match, outputs:
///   matched_phrase  -> the grammar phrase that matched
///   consumed_count  -> number of stt_queue entries to remove (1 or 2)
///
/// Returns FAILURE if no phrase matches (or queue too small for window).
class MatchGrammar : public BT::SyncActionNode
{
public:
  MatchGrammar(const std::string & name, const BT::NodeConfig & config);

  static BT::PortsList providedPorts();

  BT::NodeStatus tick() override;

private:
  static std::string normalize(std::string s);
};

}  // namespace bt_hello_dave
