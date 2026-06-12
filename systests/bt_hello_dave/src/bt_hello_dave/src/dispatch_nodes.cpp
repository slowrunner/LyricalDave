#include "bt_hello_dave/dispatch_nodes.hpp"
#include "bt_hello_dave/types.hpp"

#include <algorithm>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <sstream>

namespace bt_hello_dave
{

// ---------------------------------------------------------------------------
// LogHeard
// ---------------------------------------------------------------------------

LogHeard::LogHeard(const std::string & name, const BT::NodeConfig & config)
: BT::SyncActionNode(name, config)
{
}

BT::PortsList LogHeard::providedPorts()
{
  return {
    BT::InputPort<std::string>("phrase"),
    BT::InputPort<std::string>("log_path", DEFAULT_LOG_PATH, "Path to heard.log")
  };
}

BT::NodeStatus LogHeard::tick()
{
  std::string phrase;
  getInput("phrase", phrase);

  std::string log_path = DEFAULT_LOG_PATH;
  getInput("log_path", log_path);

  // Format: "YYYY-MM-DD HH:MM:SS|<phrase>" -- matches the Python
  // logging.Formatter('%(asctime)s|%(message)s', "%Y-%m-%d %H:%M:%S")
  auto now = std::chrono::system_clock::now();
  std::time_t now_c = std::chrono::system_clock::to_time_t(now);
  std::tm tm_buf{};
  localtime_r(&now_c, &tm_buf);

  std::ostringstream line;
  line << std::put_time(&tm_buf, "%Y-%m-%d %H:%M:%S") << "|" << phrase << "\n";

  std::ofstream ofs(log_path, std::ios::app);
  if (ofs.is_open()) {
    ofs << line.str();
  }

  return BT::NodeStatus::SUCCESS;
}

// ---------------------------------------------------------------------------
// CheckPhraseInList
// ---------------------------------------------------------------------------

CheckPhraseInList::CheckPhraseInList(const std::string & name, const BT::NodeConfig & config)
: BT::ConditionNode(name, config)
{
}

BT::PortsList CheckPhraseInList::providedPorts()
{
  return {
    BT::InputPort<std::string>("phrase"),
    BT::InputPort<std::string>("list_key")
  };
}

BT::NodeStatus CheckPhraseInList::tick()
{
  std::string phrase;
  std::string list_key;
  getInput("phrase", phrase);
  getInput("list_key", list_key);

  auto store = config().blackboard->get<std::shared_ptr<GrammarStore>>("grammar_store");
  YAML::Node grammar = store->snapshot();

  YAML::Node list = grammar[list_key];
  if (!list || !list.IsSequence()) {
    return BT::NodeStatus::FAILURE;
  }

  for (const auto & item : list) {
    if (item.as<std::string>() == phrase) {
      return BT::NodeStatus::SUCCESS;
    }
  }

  return BT::NodeStatus::FAILURE;
}

// ---------------------------------------------------------------------------
// SayRandomGreeting
// ---------------------------------------------------------------------------

SayRandomGreeting::SayRandomGreeting(
  const std::string & name,
  const BT::NodeConfig & config,
  const BT::RosNodeParams & params)
: BT::RosServiceNode<dave_interfaces::srv::Say>(name, config, params)
{
}

BT::PortsList SayRandomGreeting::providedPorts()
{
  return providedBasicPorts({});
}

std::string SayRandomGreeting::pickRandomResponse(const YAML::Node & grammar)
{
  std::vector<std::string> pool;
  for (const auto & item : grammar["random_pool"]) {
    pool.push_back(item.as<std::string>());
  }

  if (pool.empty()) {
    return "Hello.";
  }

  std::vector<size_t> candidates;
  for (size_t i = 0; i < pool.size(); ++i) {
    if (std::find(recent_.begin(), recent_.end(), i) == recent_.end()) {
      candidates.push_back(i);
    }
  }

  // Fallback if filtering emptied the pool (shouldn't happen unless
  // pool.size() <= 3)
  if (candidates.empty()) {
    for (size_t i = 0; i < pool.size(); ++i) {
      candidates.push_back(i);
    }
  }

  std::uniform_int_distribution<size_t> dist(0, candidates.size() - 1);
  size_t chosen = candidates[dist(rng_)];

  recent_.push_back(chosen);
  while (recent_.size() > 3) {
    recent_.pop_front();
  }

  return pool[chosen];
}

bool SayRandomGreeting::setRequest(typename dave_interfaces::srv::Say::Request::SharedPtr & request)
{
  auto store = config().blackboard->get<std::shared_ptr<GrammarStore>>("grammar_store");
  YAML::Node grammar = store->snapshot();

  int normal_volume = 50;
  if (grammar["responses"]["normal_volume"]) {
    normal_volume = grammar["responses"]["normal_volume"].as<int>();
  }

  request->saystring = pickRandomResponse(grammar);
  request->volume = static_cast<int8_t>(normal_volume);
  request->anytime = false;

  return true;
}

BT::NodeStatus SayRandomGreeting::onResponseReceived(
  const typename dave_interfaces::srv::Say::Response::SharedPtr & /*response*/)
{
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus SayRandomGreeting::onFailure(BT::ServiceNodeErrorCode error)
{
  RCLCPP_ERROR(node_->get_logger(), "SayRandomGreeting failed with error: %d", static_cast<int>(error));
  return BT::NodeStatus::FAILURE;
}

// ---------------------------------------------------------------------------
// BuildBatteryReport
// ---------------------------------------------------------------------------

BuildBatteryReport::BuildBatteryReport(const std::string & name, const BT::NodeConfig & config)
: BT::SyncActionNode(name, config)
{
}

BT::PortsList BuildBatteryReport::providedPorts()
{
  return {BT::OutputPort<std::string>("report_text")};
}

BT::NodeStatus BuildBatteryReport::tick()
{
  BatteryStateEntry bs;
  try {
    bs = config().blackboard->get<BatteryStateEntry>("battery_state");
  } catch (...) {
    setOutput("report_text", "Battery state is currently unavailable.");
    return BT::NodeStatus::SUCCESS;
  }

  if (!bs.valid) {
    setOutput("report_text", "Battery state is currently unavailable.");
    return BT::NodeStatus::SUCCESS;
  }

  std::ostringstream oss;
  oss << std::fixed << std::setprecision(1);

  // Voltage to one decimal place
  oss << "Voltage is " << bs.voltage << " volts. ";

  // milliamps: negative -> charging, positive -> discharging, no decimal
  long ma = std::lround(bs.milliamps);
  if (ma < 0) {
    oss << "Charging at " << -ma << " milliamps. ";
  } else {
    oss << "Discharging at " << ma << " milliamps. ";
  }

  // Power in watts, one decimal place
  oss << "Power " << bs.watts << " watts. ";

  // Percent, no decimal
  long pct = std::lround(bs.percent);
  oss << "Battery is estimated to be at " << pct << " percent.";

  setOutput("report_text", oss.str());
  return BT::NodeStatus::SUCCESS;
}

// ---------------------------------------------------------------------------
// SayFixed
// ---------------------------------------------------------------------------

SayFixed::SayFixed(
  const std::string & name,
  const BT::NodeConfig & config,
  const BT::RosNodeParams & params)
: BT::RosServiceNode<dave_interfaces::srv::Say>(name, config, params)
{
}

BT::PortsList SayFixed::providedPorts()
{
  return providedBasicPorts({
    BT::InputPort<std::string>("phrase")
  });
}

bool SayFixed::setRequest(typename dave_interfaces::srv::Say::Request::SharedPtr & request)
{
  std::string phrase;
  if (!getInput("phrase", phrase)) {
    RCLCPP_ERROR(node_->get_logger(), "SayFixed: missing required input [phrase]");
    return false;
  }

  auto store = config().blackboard->get<std::shared_ptr<GrammarStore>>("grammar_store");
  YAML::Node grammar = store->snapshot();

  YAML::Node entry = grammar["responses"]["fixed"][phrase];
  if (!entry) {
    // No fixed-response entry for this phrase -- not an error, just
    // "this node doesn't handle it", lets the enclosing Fallback try
    // (or fail through to) other branches.
    found_entry_ = false;
    return false;
  }

  found_entry_ = true;
  sets_sleep_mode_ = entry["sets_sleep_mode"] && entry["sets_sleep_mode"].as<bool>();
  clears_sleep_mode_ = entry["clears_sleep_mode"] && entry["clears_sleep_mode"].as<bool>();

  request->saystring = entry["text"].as<std::string>();
  request->volume = static_cast<int8_t>(entry["volume"].as<int>());
  request->anytime = entry["anytime"].as<bool>();

  return true;
}

BT::NodeStatus SayFixed::onResponseReceived(
  const typename dave_interfaces::srv::Say::Response::SharedPtr & /*response*/)
{
  if (sets_sleep_mode_) {
    config().blackboard->set("sleep_mode", true);
  }
  if (clears_sleep_mode_) {
    config().blackboard->set("sleep_mode", false);
  }
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus SayFixed::onFailure(BT::ServiceNodeErrorCode error)
{
  if (!found_entry_) {
    // setRequest() returned false because there's no fixed entry for
    // this phrase -- treat as a normal "doesn't apply" FAILURE, no
    // error log.
    return BT::NodeStatus::FAILURE;
  }
  RCLCPP_ERROR(node_->get_logger(), "SayFixed failed with error: %d", static_cast<int>(error));
  return BT::NodeStatus::FAILURE;
}

}  // namespace bt_hello_dave
