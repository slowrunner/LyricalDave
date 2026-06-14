#pragma once

#include <behaviortree_cpp/bt_factory.h>
#include <behaviortree_ros2/bt_service_node.hpp>
#include <dave_interfaces/srv/say.hpp>
#include <bt_hello_dave/grammar_store.hpp>
#include <deque>
#include <memory>
#include <random>
#include <string>
#include <vector>

namespace bt_hello_dave
{

// ---------------------------------------------------------------------------
// CheckSleepModeBlocksResponse
// ---------------------------------------------------------------------------

/// SUCCESS ("block the response") if the "sleep_mode" blackboard entry
/// is true AND input port "phrase" is not "wake up dave". FAILURE
/// ("allow normal dispatch") if awake, or if asleep and the phrase is
/// "wake up dave".
///
/// Intended use: placed as the first child of a Fallback that wraps
/// the normal response dispatch (greeting / battery / fixed). When
/// this node returns SUCCESS, the Fallback short-circuits and no
/// response is spoken -- but LogHeard (which runs before this node in
/// the enclosing Sequence) has already recorded the phrase, satisfying
/// "logged but not acted upon" while asleep.
class CheckSleepModeBlocksResponse : public BT::ConditionNode
{
public:
  CheckSleepModeBlocksResponse(const std::string & name, const BT::NodeConfig & config);

  static BT::PortsList providedPorts();

  BT::NodeStatus tick() override;

private:
  static constexpr const char * WAKE_PHRASE = "wake up dave";
};

// ---------------------------------------------------------------------------
// LogHeard
// ---------------------------------------------------------------------------

/// Logs the matched phrase to heard.log via the "heardLog" logger
/// (format: "YYYY-MM-DD HH:MM:SS|<phrase>", matching the original
/// Python logging.Formatter). Always returns SUCCESS.
///
/// Log path is read from the "log_path" input port, defaulting to
/// /home/ubuntu/LyricalDave/logs/heard.log.
class LogHeard : public BT::SyncActionNode
{
public:
  LogHeard(const std::string & name, const BT::NodeConfig & config);

  static BT::PortsList providedPorts();

  BT::NodeStatus tick() override;

private:
  static constexpr const char * DEFAULT_LOG_PATH =
    "/home/ubuntu/LyricalDave/logs/heard.log";
};

// ---------------------------------------------------------------------------
// CheckPhraseInList
// ---------------------------------------------------------------------------

/// SUCCESS if input port "phrase" is found in the grammar YAML list
/// named by input port "list_key" (e.g. "greeting_phrases" or
/// "battery_phrases" under the document root). FAILURE otherwise.
///
/// Reads the GrammarStore from the "grammar_store" blackboard entry,
/// so list contents reflect the latest reload.
class CheckPhraseInList : public BT::ConditionNode
{
public:
  CheckPhraseInList(const std::string & name, const BT::NodeConfig & config);

  static BT::PortsList providedPorts();

  BT::NodeStatus tick() override;
};

// ---------------------------------------------------------------------------
// SayRandomGreeting
// ---------------------------------------------------------------------------

/// Picks a random response from grammar["random_pool"], excluding the
/// 3 most-recently used entries (anti-repeat, matching the Python
/// Random_Hello_Response.get_filtered_response() behavior), then calls
/// /say with that text at normal volume, anytime=false.
///
/// Picker history is kept in-instance (per node instance, i.e. per
/// tree), reset only on process restart.
class SayRandomGreeting : public BT::RosServiceNode<dave_interfaces::srv::Say>
{
public:
  SayRandomGreeting(
    const std::string & name,
    const BT::NodeConfig & config,
    const BT::RosNodeParams & params);

  static BT::PortsList providedPorts();

  bool setRequest(typename dave_interfaces::srv::Say::Request::SharedPtr & request) override;

  BT::NodeStatus onResponseReceived(
    const typename dave_interfaces::srv::Say::Response::SharedPtr & response) override;

  BT::NodeStatus onFailure(BT::ServiceNodeErrorCode error) override;

private:
  std::string pickRandomResponse(const YAML::Node & grammar);

  std::deque<size_t> recent_;
  std::mt19937 rng_{std::random_device{}()};
};

// ---------------------------------------------------------------------------
// BuildBatteryReport
// ---------------------------------------------------------------------------

/// Reads the "battery_state" blackboard entry (BatteryStateEntry) and
/// formats a spoken report:
///   "Voltage is X.X volts. {Charging|Discharging} at NNN milliamps.
///    Power X.X watts. Battery is estimated to be at NNN percent."
///
/// Output port "report_text" receives the formatted string.
/// Returns FAILURE if no battery_state has been received yet.
class BuildBatteryReport : public BT::SyncActionNode
{
public:
  BuildBatteryReport(const std::string & name, const BT::NodeConfig & config);

  static BT::PortsList providedPorts();

  BT::NodeStatus tick() override;
};

// ---------------------------------------------------------------------------
// SayFixed
// ---------------------------------------------------------------------------

/// Data-driven "fixed phrase -> fixed response" node. Looks up the
/// input port "phrase" in grammar["responses"]["fixed"][phrase] and,
/// if found, calls /say with that entry's text/volume/anytime, then
/// applies post_delay (blocking via internal RUNNING state), and sets
/// or clears "sleep_mode" on the blackboard per the entry's
/// sets_sleep_mode / clears_sleep_mode flags.
///
/// Returns FAILURE if "phrase" has no entry in the fixed map (so the
/// enclosing Fallback can fall through / fail as appropriate).
///
/// This node performs NO custom processing beyond the YAML-described
/// say + delay + sleep-mode flag — purely data driven.
class SayFixed : public BT::RosServiceNode<dave_interfaces::srv::Say>
{
public:
  SayFixed(
    const std::string & name,
    const BT::NodeConfig & config,
    const BT::RosNodeParams & params);

  static BT::PortsList providedPorts();

  bool setRequest(typename dave_interfaces::srv::Say::Request::SharedPtr & request) override;

  BT::NodeStatus onResponseReceived(
    const typename dave_interfaces::srv::Say::Response::SharedPtr & response) override;

  BT::NodeStatus onFailure(BT::ServiceNodeErrorCode error) override;

private:
  // Cached on setRequest(), used in onResponseReceived() to apply
  // sleep_mode flags. post_delay is intentionally NOT blocked on here;
  // see bt_hello_dave_tree.xml note about DelaySeconds if a blocking
  // post-delay is required between responses.
  bool sets_sleep_mode_ = false;
  bool clears_sleep_mode_ = false;
  bool found_entry_ = false;
};

}  // namespace bt_hello_dave
