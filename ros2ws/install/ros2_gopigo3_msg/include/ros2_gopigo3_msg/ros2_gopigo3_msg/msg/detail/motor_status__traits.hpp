// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_gopigo3_msg:msg/MotorStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros2_gopigo3_msg/msg/motor_status.hpp"


#ifndef ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS__TRAITS_HPP_
#define ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "ros2_gopigo3_msg/msg/detail/motor_status__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros2_gopigo3_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: low_voltage
  {
    out << "low_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.low_voltage, out);
    out << ", ";
  }

  // member: overloaded
  {
    out << "overloaded: ";
    rosidl_generator_traits::value_to_yaml(msg.overloaded, out);
    out << ", ";
  }

  // member: power
  {
    out << "power: ";
    rosidl_generator_traits::value_to_yaml(msg.power, out);
    out << ", ";
  }

  // member: encoder
  {
    out << "encoder: ";
    rosidl_generator_traits::value_to_yaml(msg.encoder, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: low_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "low_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.low_voltage, out);
    out << "\n";
  }

  // member: overloaded
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "overloaded: ";
    rosidl_generator_traits::value_to_yaml(msg.overloaded, out);
    out << "\n";
  }

  // member: power
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "power: ";
    rosidl_generator_traits::value_to_yaml(msg.power, out);
    out << "\n";
  }

  // member: encoder
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "encoder: ";
    rosidl_generator_traits::value_to_yaml(msg.encoder, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, ros2_gopigo3_msg::msg::MotorStatus>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).low_voltage,
    std::forward<T>(msg).overloaded,
    std::forward<T>(msg).power,
    std::forward<T>(msg).encoder,
    std::forward<T>(msg).speed);
}

}  // namespace msg

}  // namespace ros2_gopigo3_msg

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<ros2_gopigo3_msg::msg::MotorStatus>()
{
  return "ros2_gopigo3_msg::msg::MotorStatus";
}

template<>
constexpr const char * name<ros2_gopigo3_msg::msg::MotorStatus>()
{
  return "ros2_gopigo3_msg/msg/MotorStatus";
}

template<>
struct has_fixed_size<ros2_gopigo3_msg::msg::MotorStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros2_gopigo3_msg::msg::MotorStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros2_gopigo3_msg::msg::MotorStatus>
  : std::true_type {};

template<>
struct MessageTraits<ros2_gopigo3_msg::msg::MotorStatus>
{
  static constexpr std::size_t member_count = 5;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "low_voltage",
    "overloaded",
    "power",
    "encoder",
    "speed",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS__TRAITS_HPP_
