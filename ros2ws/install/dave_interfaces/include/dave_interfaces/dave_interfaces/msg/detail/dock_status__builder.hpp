// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dave_interfaces:msg/DockStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dave_interfaces/msg/dock_status.hpp"


#ifndef DAVE_INTERFACES__MSG__DETAIL__DOCK_STATUS__BUILDER_HPP_
#define DAVE_INTERFACES__MSG__DETAIL__DOCK_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dave_interfaces/msg/detail/dock_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dave_interfaces
{

namespace msg
{

namespace builder
{

class Init_DockStatus_is_charging
{
public:
  explicit Init_DockStatus_is_charging(::dave_interfaces::msg::DockStatus & msg)
  : msg_(msg)
  {}
  ::dave_interfaces::msg::DockStatus is_charging(::dave_interfaces::msg::DockStatus::_is_charging_type arg)
  {
    msg_.is_charging = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dave_interfaces::msg::DockStatus msg_;
};

class Init_DockStatus_is_docked
{
public:
  Init_DockStatus_is_docked()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DockStatus_is_charging is_docked(::dave_interfaces::msg::DockStatus::_is_docked_type arg)
  {
    msg_.is_docked = std::move(arg);
    return Init_DockStatus_is_charging(msg_);
  }

private:
  ::dave_interfaces::msg::DockStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dave_interfaces::msg::DockStatus>()
{
  return dave_interfaces::msg::builder::Init_DockStatus_is_docked();
}

}  // namespace dave_interfaces

#endif  // DAVE_INTERFACES__MSG__DETAIL__DOCK_STATUS__BUILDER_HPP_
