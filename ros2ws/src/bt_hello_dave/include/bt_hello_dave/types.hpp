#pragma once

#include <chrono>
#include <deque>
#include <string>
#include <rclcpp/time.hpp>

namespace bt_hello_dave
{

/// Convenience alias for the steady clock time point used for mute timing.
using TimePoint = std::chrono::steady_clock::time_point;

/// Grace period after /say returns with spoken==true during which
/// incoming /stt/result messages are still dropped (absorbs mic/room
/// tail after TTS playback ends).
inline constexpr std::chrono::milliseconds SPEAKING_GRACE_PERIOD{500};

/// Safety ceiling: if @speaking stays true longer than this (e.g. due
/// to a crashed say_node that never sent a response), auto-clear mute
/// so the system self-heals rather than going permanently deaf.
inline constexpr std::chrono::milliseconds SPEAKING_TIMEOUT_CEILING{20000};

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
