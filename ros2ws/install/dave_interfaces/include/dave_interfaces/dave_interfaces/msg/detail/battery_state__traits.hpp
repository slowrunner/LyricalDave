// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dave_interfaces:msg/BatteryState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dave_interfaces/msg/battery_state.hpp"


#ifndef DAVE_INTERFACES__MSG__DETAIL__BATTERY_STATE__TRAITS_HPP_
#define DAVE_INTERFACES__MSG__DETAIL__BATTERY_STATE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "dave_interfaces/msg/detail/battery_state__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace dave_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const BatteryState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: volts
  {
    out << "volts: ";
    rosidl_generator_traits::value_to_yaml(msg.volts, out);
    out << ", ";
  }

  // member: milliamps
  {
    out << "milliamps: ";
    rosidl_generator_traits::value_to_yaml(msg.milliamps, out);
    out << ", ";
  }

  // member: watts
  {
    out << "watts: ";
    rosidl_generator_traits::value_to_yaml(msg.watts, out);
    out << ", ";
  }

  // member: watthours
  {
    out << "watthours: ";
    rosidl_generator_traits::value_to_yaml(msg.watthours, out);
    out << ", ";
  }

  // member: charging
  {
    out << "charging: ";
    rosidl_generator_traits::value_to_yaml(msg.charging, out);
    out << ", ";
  }

  // member: capacity
  {
    out << "capacity: ";
    rosidl_generator_traits::value_to_yaml(msg.capacity, out);
    out << ", ";
  }

  // member: percent
  {
    out << "percent: ";
    rosidl_generator_traits::value_to_yaml(msg.percent, out);
    out << ", ";
  }

  // member: last_charge
  {
    out << "last_charge: ";
    rosidl_generator_traits::value_to_yaml(msg.last_charge, out);
    out << ", ";
  }

  // member: last_discharge
  {
    out << "last_discharge: ";
    rosidl_generator_traits::value_to_yaml(msg.last_discharge, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BatteryState & msg,
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

  // member: volts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "volts: ";
    rosidl_generator_traits::value_to_yaml(msg.volts, out);
    out << "\n";
  }

  // member: milliamps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "milliamps: ";
    rosidl_generator_traits::value_to_yaml(msg.milliamps, out);
    out << "\n";
  }

  // member: watts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "watts: ";
    rosidl_generator_traits::value_to_yaml(msg.watts, out);
    out << "\n";
  }

  // member: watthours
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "watthours: ";
    rosidl_generator_traits::value_to_yaml(msg.watthours, out);
    out << "\n";
  }

  // member: charging
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "charging: ";
    rosidl_generator_traits::value_to_yaml(msg.charging, out);
    out << "\n";
  }

  // member: capacity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "capacity: ";
    rosidl_generator_traits::value_to_yaml(msg.capacity, out);
    out << "\n";
  }

  // member: percent
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "percent: ";
    rosidl_generator_traits::value_to_yaml(msg.percent, out);
    out << "\n";
  }

  // member: last_charge
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_charge: ";
    rosidl_generator_traits::value_to_yaml(msg.last_charge, out);
    out << "\n";
  }

  // member: last_discharge
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_discharge: ";
    rosidl_generator_traits::value_to_yaml(msg.last_discharge, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BatteryState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, dave_interfaces::msg::BatteryState>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).header,
    std::forward<T>(msg).volts,
    std::forward<T>(msg).milliamps,
    std::forward<T>(msg).watts,
    std::forward<T>(msg).watthours,
    std::forward<T>(msg).charging,
    std::forward<T>(msg).capacity,
    std::forward<T>(msg).percent,
    std::forward<T>(msg).last_charge,
    std::forward<T>(msg).last_discharge);
}

}  // namespace msg

}  // namespace dave_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<dave_interfaces::msg::BatteryState>()
{
  return "dave_interfaces::msg::BatteryState";
}

template<>
constexpr const char * name<dave_interfaces::msg::BatteryState>()
{
  return "dave_interfaces/msg/BatteryState";
}

template<>
struct has_fixed_size<dave_interfaces::msg::BatteryState>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<dave_interfaces::msg::BatteryState>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<dave_interfaces::msg::BatteryState>
  : std::true_type {};

template<>
struct MessageTraits<dave_interfaces::msg::BatteryState>
{
  static constexpr std::size_t member_count = 10;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "header",
    "volts",
    "milliamps",
    "watts",
    "watthours",
    "charging",
    "capacity",
    "percent",
    "last_charge",
    "last_discharge",
  };
};

}  // namespace rosidl_generator_traits

#endif  // DAVE_INTERFACES__MSG__DETAIL__BATTERY_STATE__TRAITS_HPP_
