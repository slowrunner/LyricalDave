// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dave_interfaces:msg/BatteryState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dave_interfaces/msg/battery_state.hpp"


#ifndef DAVE_INTERFACES__MSG__DETAIL__BATTERY_STATE__BUILDER_HPP_
#define DAVE_INTERFACES__MSG__DETAIL__BATTERY_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dave_interfaces/msg/detail/battery_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dave_interfaces
{

namespace msg
{

namespace builder
{

class Init_BatteryState_last_discharge
{
public:
  explicit Init_BatteryState_last_discharge(::dave_interfaces::msg::BatteryState & msg)
  : msg_(msg)
  {}
  ::dave_interfaces::msg::BatteryState last_discharge(::dave_interfaces::msg::BatteryState::_last_discharge_type arg)
  {
    msg_.last_discharge = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dave_interfaces::msg::BatteryState msg_;
};

class Init_BatteryState_last_charge
{
public:
  explicit Init_BatteryState_last_charge(::dave_interfaces::msg::BatteryState & msg)
  : msg_(msg)
  {}
  Init_BatteryState_last_discharge last_charge(::dave_interfaces::msg::BatteryState::_last_charge_type arg)
  {
    msg_.last_charge = std::move(arg);
    return Init_BatteryState_last_discharge(msg_);
  }

private:
  ::dave_interfaces::msg::BatteryState msg_;
};

class Init_BatteryState_percent
{
public:
  explicit Init_BatteryState_percent(::dave_interfaces::msg::BatteryState & msg)
  : msg_(msg)
  {}
  Init_BatteryState_last_charge percent(::dave_interfaces::msg::BatteryState::_percent_type arg)
  {
    msg_.percent = std::move(arg);
    return Init_BatteryState_last_charge(msg_);
  }

private:
  ::dave_interfaces::msg::BatteryState msg_;
};

class Init_BatteryState_capacity
{
public:
  explicit Init_BatteryState_capacity(::dave_interfaces::msg::BatteryState & msg)
  : msg_(msg)
  {}
  Init_BatteryState_percent capacity(::dave_interfaces::msg::BatteryState::_capacity_type arg)
  {
    msg_.capacity = std::move(arg);
    return Init_BatteryState_percent(msg_);
  }

private:
  ::dave_interfaces::msg::BatteryState msg_;
};

class Init_BatteryState_charging
{
public:
  explicit Init_BatteryState_charging(::dave_interfaces::msg::BatteryState & msg)
  : msg_(msg)
  {}
  Init_BatteryState_capacity charging(::dave_interfaces::msg::BatteryState::_charging_type arg)
  {
    msg_.charging = std::move(arg);
    return Init_BatteryState_capacity(msg_);
  }

private:
  ::dave_interfaces::msg::BatteryState msg_;
};

class Init_BatteryState_watthours
{
public:
  explicit Init_BatteryState_watthours(::dave_interfaces::msg::BatteryState & msg)
  : msg_(msg)
  {}
  Init_BatteryState_charging watthours(::dave_interfaces::msg::BatteryState::_watthours_type arg)
  {
    msg_.watthours = std::move(arg);
    return Init_BatteryState_charging(msg_);
  }

private:
  ::dave_interfaces::msg::BatteryState msg_;
};

class Init_BatteryState_watts
{
public:
  explicit Init_BatteryState_watts(::dave_interfaces::msg::BatteryState & msg)
  : msg_(msg)
  {}
  Init_BatteryState_watthours watts(::dave_interfaces::msg::BatteryState::_watts_type arg)
  {
    msg_.watts = std::move(arg);
    return Init_BatteryState_watthours(msg_);
  }

private:
  ::dave_interfaces::msg::BatteryState msg_;
};

class Init_BatteryState_milliamps
{
public:
  explicit Init_BatteryState_milliamps(::dave_interfaces::msg::BatteryState & msg)
  : msg_(msg)
  {}
  Init_BatteryState_watts milliamps(::dave_interfaces::msg::BatteryState::_milliamps_type arg)
  {
    msg_.milliamps = std::move(arg);
    return Init_BatteryState_watts(msg_);
  }

private:
  ::dave_interfaces::msg::BatteryState msg_;
};

class Init_BatteryState_volts
{
public:
  explicit Init_BatteryState_volts(::dave_interfaces::msg::BatteryState & msg)
  : msg_(msg)
  {}
  Init_BatteryState_milliamps volts(::dave_interfaces::msg::BatteryState::_volts_type arg)
  {
    msg_.volts = std::move(arg);
    return Init_BatteryState_milliamps(msg_);
  }

private:
  ::dave_interfaces::msg::BatteryState msg_;
};

class Init_BatteryState_header
{
public:
  Init_BatteryState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BatteryState_volts header(::dave_interfaces::msg::BatteryState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BatteryState_volts(msg_);
  }

private:
  ::dave_interfaces::msg::BatteryState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dave_interfaces::msg::BatteryState>()
{
  return dave_interfaces::msg::builder::Init_BatteryState_header();
}

}  // namespace dave_interfaces

#endif  // DAVE_INTERFACES__MSG__DETAIL__BATTERY_STATE__BUILDER_HPP_
