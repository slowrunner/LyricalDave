// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dave_interfaces:msg/BatteryState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dave_interfaces/msg/battery_state.hpp"


#ifndef DAVE_INTERFACES__MSG__DETAIL__BATTERY_STATE__STRUCT_HPP_
#define DAVE_INTERFACES__MSG__DETAIL__BATTERY_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_buffer/buffer.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dave_interfaces__msg__BatteryState __attribute__((deprecated))
#else
# define DEPRECATED__dave_interfaces__msg__BatteryState __declspec(deprecated)
#endif

namespace dave_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BatteryState_
{
  using Type = BatteryState_<ContainerAllocator>;

  explicit BatteryState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->volts = 0.0f;
      this->milliamps = 0.0f;
      this->watts = 0.0f;
      this->watthours = 0.0f;
      this->charging = false;
      this->capacity = 0;
      this->percent = 0;
      this->last_charge = 0.0f;
      this->last_discharge = 0.0f;
    }
  }

  explicit BatteryState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->volts = 0.0f;
      this->milliamps = 0.0f;
      this->watts = 0.0f;
      this->watthours = 0.0f;
      this->charging = false;
      this->capacity = 0;
      this->percent = 0;
      this->last_charge = 0.0f;
      this->last_discharge = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _volts_type =
    float;
  _volts_type volts;
  using _milliamps_type =
    float;
  _milliamps_type milliamps;
  using _watts_type =
    float;
  _watts_type watts;
  using _watthours_type =
    float;
  _watthours_type watthours;
  using _charging_type =
    bool;
  _charging_type charging;
  using _capacity_type =
    int16_t;
  _capacity_type capacity;
  using _percent_type =
    int16_t;
  _percent_type percent;
  using _last_charge_type =
    float;
  _last_charge_type last_charge;
  using _last_discharge_type =
    float;
  _last_discharge_type last_discharge;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__volts(
    const float & _arg)
  {
    this->volts = _arg;
    return *this;
  }
  Type & set__milliamps(
    const float & _arg)
  {
    this->milliamps = _arg;
    return *this;
  }
  Type & set__watts(
    const float & _arg)
  {
    this->watts = _arg;
    return *this;
  }
  Type & set__watthours(
    const float & _arg)
  {
    this->watthours = _arg;
    return *this;
  }
  Type & set__charging(
    const bool & _arg)
  {
    this->charging = _arg;
    return *this;
  }
  Type & set__capacity(
    const int16_t & _arg)
  {
    this->capacity = _arg;
    return *this;
  }
  Type & set__percent(
    const int16_t & _arg)
  {
    this->percent = _arg;
    return *this;
  }
  Type & set__last_charge(
    const float & _arg)
  {
    this->last_charge = _arg;
    return *this;
  }
  Type & set__last_discharge(
    const float & _arg)
  {
    this->last_discharge = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dave_interfaces::msg::BatteryState_<ContainerAllocator> *;
  using ConstRawPtr =
    const dave_interfaces::msg::BatteryState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dave_interfaces::msg::BatteryState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dave_interfaces::msg::BatteryState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dave_interfaces::msg::BatteryState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dave_interfaces::msg::BatteryState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dave_interfaces::msg::BatteryState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dave_interfaces::msg::BatteryState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dave_interfaces::msg::BatteryState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dave_interfaces::msg::BatteryState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dave_interfaces__msg__BatteryState
    std::shared_ptr<dave_interfaces::msg::BatteryState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dave_interfaces__msg__BatteryState
    std::shared_ptr<dave_interfaces::msg::BatteryState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BatteryState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->volts != other.volts) {
      return false;
    }
    if (this->milliamps != other.milliamps) {
      return false;
    }
    if (this->watts != other.watts) {
      return false;
    }
    if (this->watthours != other.watthours) {
      return false;
    }
    if (this->charging != other.charging) {
      return false;
    }
    if (this->capacity != other.capacity) {
      return false;
    }
    if (this->percent != other.percent) {
      return false;
    }
    if (this->last_charge != other.last_charge) {
      return false;
    }
    if (this->last_discharge != other.last_discharge) {
      return false;
    }
    return true;
  }
  bool operator!=(const BatteryState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BatteryState_

// alias to use template instance with default allocator
using BatteryState =
  dave_interfaces::msg::BatteryState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dave_interfaces

#endif  // DAVE_INTERFACES__MSG__DETAIL__BATTERY_STATE__STRUCT_HPP_
