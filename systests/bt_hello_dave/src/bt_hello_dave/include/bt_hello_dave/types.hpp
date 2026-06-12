#pragma once

#include <chrono>
#include <deque>
#include <string>
#include <rclcpp/time.hpp>

namespace bt_hello_dave
{

/// A single /stt/result message stored on the blackboard, with both
/// ROS time and local wall-clock time recorded at receipt.
struct SttEntry
{
  std::string text;
  rclcpp::Time ros_time;
  std::chrono::system_clock::time_point local_time;
};

/// Latest /battery_state reading, with both ROS time and local
/// wall-clock time recorded at receipt.
struct BatteryStateEntry
{
  double voltage   = 0.0;
  double milliamps = 0.0;
  double watts     = 0.0;
  double percent   = 0.0;

  rclcpp::Time ros_time;
  std::chrono::system_clock::time_point local_time;

  bool valid = false;
};

using SttQueue = std::deque<SttEntry>;

}  // namespace bt_hello_dave
