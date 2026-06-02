// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dave_interfaces:msg/DockStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dave_interfaces/msg/dock_status.hpp"


#ifndef DAVE_INTERFACES__MSG__DETAIL__DOCK_STATUS__TRAITS_HPP_
#define DAVE_INTERFACES__MSG__DETAIL__DOCK_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "dave_interfaces/msg/detail/dock_status__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dave_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DockStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_docked
  {
    out << "is_docked: ";
    rosidl_generator_traits::value_to_yaml(msg.is_docked, out);
    out << ", ";
  }

  // member: is_charging
  {
    out << "is_charging: ";
    rosidl_generator_traits::value_to_yaml(msg.is_charging, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DockStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_docked
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_docked: ";
    rosidl_generator_traits::value_to_yaml(msg.is_docked, out);
    out << "\n";
  }

  // member: is_charging
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_charging: ";
    rosidl_generator_traits::value_to_yaml(msg.is_charging, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DockStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, dave_interfaces::msg::DockStatus>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).is_docked,
    std::forward<T>(msg).is_charging);
}

}  // namespace msg

}  // namespace dave_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<dave_interfaces::msg::DockStatus>()
{
  return "dave_interfaces::msg::DockStatus";
}

template<>
constexpr const char * name<dave_interfaces::msg::DockStatus>()
{
  return "dave_interfaces/msg/DockStatus";
}

template<>
struct has_fixed_size<dave_interfaces::msg::DockStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dave_interfaces::msg::DockStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dave_interfaces::msg::DockStatus>
  : std::true_type {};

template<>
struct MessageTraits<dave_interfaces::msg::DockStatus>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "is_docked",
    "is_charging",
  };
};

}  // namespace rosidl_generator_traits

#endif  // DAVE_INTERFACES__MSG__DETAIL__DOCK_STATUS__TRAITS_HPP_
