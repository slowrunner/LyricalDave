// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dave_interfaces:srv/Dock.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dave_interfaces/srv/dock.hpp"


#ifndef DAVE_INTERFACES__SRV__DETAIL__DOCK__BUILDER_HPP_
#define DAVE_INTERFACES__SRV__DETAIL__DOCK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dave_interfaces/srv/detail/dock__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dave_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dave_interfaces::srv::Dock_Request>()
{
  return ::dave_interfaces::srv::Dock_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace dave_interfaces


namespace dave_interfaces
{

namespace srv
{

namespace builder
{

class Init_Dock_Response_success
{
public:
  explicit Init_Dock_Response_success(::dave_interfaces::srv::Dock_Response & msg)
  : msg_(msg)
  {}
  ::dave_interfaces::srv::Dock_Response success(::dave_interfaces::srv::Dock_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dave_interfaces::srv::Dock_Response msg_;
};

class Init_Dock_Response_is_charging
{
public:
  explicit Init_Dock_Response_is_charging(::dave_interfaces::srv::Dock_Response & msg)
  : msg_(msg)
  {}
  Init_Dock_Response_success is_charging(::dave_interfaces::srv::Dock_Response::_is_charging_type arg)
  {
    msg_.is_charging = std::move(arg);
    return Init_Dock_Response_success(msg_);
  }

private:
  ::dave_interfaces::srv::Dock_Response msg_;
};

class Init_Dock_Response_is_docked
{
public:
  Init_Dock_Response_is_docked()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Dock_Response_is_charging is_docked(::dave_interfaces::srv::Dock_Response::_is_docked_type arg)
  {
    msg_.is_docked = std::move(arg);
    return Init_Dock_Response_is_charging(msg_);
  }

private:
  ::dave_interfaces::srv::Dock_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dave_interfaces::srv::Dock_Response>()
{
  return dave_interfaces::srv::builder::Init_Dock_Response_is_docked();
}

}  // namespace dave_interfaces


namespace dave_interfaces
{

namespace srv
{

namespace builder
{

class Init_Dock_Event_response
{
public:
  explicit Init_Dock_Event_response(::dave_interfaces::srv::Dock_Event & msg)
  : msg_(msg)
  {}
  ::dave_interfaces::srv::Dock_Event response(::dave_interfaces::srv::Dock_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dave_interfaces::srv::Dock_Event msg_;
};

class Init_Dock_Event_request
{
public:
  explicit Init_Dock_Event_request(::dave_interfaces::srv::Dock_Event & msg)
  : msg_(msg)
  {}
  Init_Dock_Event_response request(::dave_interfaces::srv::Dock_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Dock_Event_response(msg_);
  }

private:
  ::dave_interfaces::srv::Dock_Event msg_;
};

class Init_Dock_Event_info
{
public:
  Init_Dock_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Dock_Event_request info(::dave_interfaces::srv::Dock_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Dock_Event_request(msg_);
  }

private:
  ::dave_interfaces::srv::Dock_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dave_interfaces::srv::Dock_Event>()
{
  return dave_interfaces::srv::builder::Init_Dock_Event_info();
}

}  // namespace dave_interfaces

#endif  // DAVE_INTERFACES__SRV__DETAIL__DOCK__BUILDER_HPP_
