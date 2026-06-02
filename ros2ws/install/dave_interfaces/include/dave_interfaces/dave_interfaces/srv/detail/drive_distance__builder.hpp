// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dave_interfaces:srv/DriveDistance.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dave_interfaces/srv/drive_distance.hpp"


#ifndef DAVE_INTERFACES__SRV__DETAIL__DRIVE_DISTANCE__BUILDER_HPP_
#define DAVE_INTERFACES__SRV__DETAIL__DRIVE_DISTANCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dave_interfaces/srv/detail/drive_distance__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dave_interfaces
{

namespace srv
{

namespace builder
{

class Init_DriveDistance_Request_speed
{
public:
  explicit Init_DriveDistance_Request_speed(::dave_interfaces::srv::DriveDistance_Request & msg)
  : msg_(msg)
  {}
  ::dave_interfaces::srv::DriveDistance_Request speed(::dave_interfaces::srv::DriveDistance_Request::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dave_interfaces::srv::DriveDistance_Request msg_;
};

class Init_DriveDistance_Request_distance
{
public:
  Init_DriveDistance_Request_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DriveDistance_Request_speed distance(::dave_interfaces::srv::DriveDistance_Request::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_DriveDistance_Request_speed(msg_);
  }

private:
  ::dave_interfaces::srv::DriveDistance_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dave_interfaces::srv::DriveDistance_Request>()
{
  return dave_interfaces::srv::builder::Init_DriveDistance_Request_distance();
}

}  // namespace dave_interfaces


namespace dave_interfaces
{

namespace srv
{

namespace builder
{

class Init_DriveDistance_Response_status
{
public:
  Init_DriveDistance_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dave_interfaces::srv::DriveDistance_Response status(::dave_interfaces::srv::DriveDistance_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dave_interfaces::srv::DriveDistance_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dave_interfaces::srv::DriveDistance_Response>()
{
  return dave_interfaces::srv::builder::Init_DriveDistance_Response_status();
}

}  // namespace dave_interfaces


namespace dave_interfaces
{

namespace srv
{

namespace builder
{

class Init_DriveDistance_Event_response
{
public:
  explicit Init_DriveDistance_Event_response(::dave_interfaces::srv::DriveDistance_Event & msg)
  : msg_(msg)
  {}
  ::dave_interfaces::srv::DriveDistance_Event response(::dave_interfaces::srv::DriveDistance_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dave_interfaces::srv::DriveDistance_Event msg_;
};

class Init_DriveDistance_Event_request
{
public:
  explicit Init_DriveDistance_Event_request(::dave_interfaces::srv::DriveDistance_Event & msg)
  : msg_(msg)
  {}
  Init_DriveDistance_Event_response request(::dave_interfaces::srv::DriveDistance_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_DriveDistance_Event_response(msg_);
  }

private:
  ::dave_interfaces::srv::DriveDistance_Event msg_;
};

class Init_DriveDistance_Event_info
{
public:
  Init_DriveDistance_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DriveDistance_Event_request info(::dave_interfaces::srv::DriveDistance_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_DriveDistance_Event_request(msg_);
  }

private:
  ::dave_interfaces::srv::DriveDistance_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dave_interfaces::srv::DriveDistance_Event>()
{
  return dave_interfaces::srv::builder::Init_DriveDistance_Event_info();
}

}  // namespace dave_interfaces

#endif  // DAVE_INTERFACES__SRV__DETAIL__DRIVE_DISTANCE__BUILDER_HPP_
