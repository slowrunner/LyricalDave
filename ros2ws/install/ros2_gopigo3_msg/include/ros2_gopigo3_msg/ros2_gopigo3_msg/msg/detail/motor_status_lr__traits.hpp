// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_gopigo3_msg:msg/MotorStatusLR.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros2_gopigo3_msg/msg/motor_status_lr.hpp"


#ifndef ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS_LR__TRAITS_HPP_
#define ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS_LR__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "ros2_gopigo3_msg/msg/detail/motor_status_lr__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'left'
// Member 'right'
#include "ros2_gopigo3_msg/msg/detail/motor_status__traits.hpp"

namespace ros2_gopigo3_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorStatusLR & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: left
  {
    out << "left: ";
    to_flow_style_yaml(msg.left, out);
    out << ", ";
  }

  // member: right
  {
    out << "right: ";
    to_flow_style_yaml(msg.right, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorStatusLR & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left:\n";
    to_block_style_yaml(msg.left, out, indentation + 2);
  }

  // member: right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right:\n";
    to_block_style_yaml(msg.right, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorStatusLR & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, ros2_gopigo3_msg::msg::MotorStatusLR>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).header,
    std::forward<T>(msg).left,
    std::forward<T>(msg).right);
}

}  // namespace msg

}  // namespace ros2_gopigo3_msg

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<ros2_gopigo3_msg::msg::MotorStatusLR>()
{
  return "ros2_gopigo3_msg::msg::MotorStatusLR";
}

template<>
constexpr const char * name<ros2_gopigo3_msg::msg::MotorStatusLR>()
{
  return "ros2_gopigo3_msg/msg/MotorStatusLR";
}

template<>
struct has_fixed_size<ros2_gopigo3_msg::msg::MotorStatusLR>
  : std::integral_constant<bool, has_fixed_size<ros2_gopigo3_msg::msg::MotorStatus>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<ros2_gopigo3_msg::msg::MotorStatusLR>
  : std::integral_constant<bool, has_bounded_size<ros2_gopigo3_msg::msg::MotorStatus>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<ros2_gopigo3_msg::msg::MotorStatusLR>
  : std::true_type {};

template<>
struct MessageTraits<ros2_gopigo3_msg::msg::MotorStatusLR>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "header",
    "left",
    "right",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS_LR__TRAITS_HPP_
