// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dave_interfaces:msg/DockStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dave_interfaces/msg/dock_status.hpp"


#ifndef DAVE_INTERFACES__MSG__DETAIL__DOCK_STATUS__STRUCT_HPP_
#define DAVE_INTERFACES__MSG__DETAIL__DOCK_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_buffer/buffer.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dave_interfaces__msg__DockStatus __attribute__((deprecated))
#else
# define DEPRECATED__dave_interfaces__msg__DockStatus __declspec(deprecated)
#endif

namespace dave_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DockStatus_
{
  using Type = DockStatus_<ContainerAllocator>;

  explicit DockStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_docked = false;
      this->is_charging = false;
    }
  }

  explicit DockStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_docked = false;
      this->is_charging = false;
    }
  }

  // field types and members
  using _is_docked_type =
    bool;
  _is_docked_type is_docked;
  using _is_charging_type =
    bool;
  _is_charging_type is_charging;

  // setters for named parameter idiom
  Type & set__is_docked(
    const bool & _arg)
  {
    this->is_docked = _arg;
    return *this;
  }
  Type & set__is_charging(
    const bool & _arg)
  {
    this->is_charging = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dave_interfaces::msg::DockStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const dave_interfaces::msg::DockStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dave_interfaces::msg::DockStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dave_interfaces::msg::DockStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dave_interfaces::msg::DockStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dave_interfaces::msg::DockStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dave_interfaces::msg::DockStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dave_interfaces::msg::DockStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dave_interfaces::msg::DockStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dave_interfaces::msg::DockStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dave_interfaces__msg__DockStatus
    std::shared_ptr<dave_interfaces::msg::DockStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dave_interfaces__msg__DockStatus
    std::shared_ptr<dave_interfaces::msg::DockStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DockStatus_ & other) const
  {
    if (this->is_docked != other.is_docked) {
      return false;
    }
    if (this->is_charging != other.is_charging) {
      return false;
    }
    return true;
  }
  bool operator!=(const DockStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DockStatus_

// alias to use template instance with default allocator
using DockStatus =
  dave_interfaces::msg::DockStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dave_interfaces

#endif  // DAVE_INTERFACES__MSG__DETAIL__DOCK_STATUS__STRUCT_HPP_
