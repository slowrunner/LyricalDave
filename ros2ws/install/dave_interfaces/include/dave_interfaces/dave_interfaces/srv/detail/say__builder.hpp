// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dave_interfaces:srv/Say.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dave_interfaces/srv/say.hpp"


#ifndef DAVE_INTERFACES__SRV__DETAIL__SAY__BUILDER_HPP_
#define DAVE_INTERFACES__SRV__DETAIL__SAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dave_interfaces/srv/detail/say__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dave_interfaces
{

namespace srv
{

namespace builder
{

class Init_Say_Request_saystring
{
public:
  Init_Say_Request_saystring()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dave_interfaces::srv::Say_Request saystring(::dave_interfaces::srv::Say_Request::_saystring_type arg)
  {
    msg_.saystring = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dave_interfaces::srv::Say_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dave_interfaces::srv::Say_Request>()
{
  return dave_interfaces::srv::builder::Init_Say_Request_saystring();
}

}  // namespace dave_interfaces


namespace dave_interfaces
{

namespace srv
{

namespace builder
{

class Init_Say_Response_spoken
{
public:
  Init_Say_Response_spoken()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dave_interfaces::srv::Say_Response spoken(::dave_interfaces::srv::Say_Response::_spoken_type arg)
  {
    msg_.spoken = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dave_interfaces::srv::Say_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dave_interfaces::srv::Say_Response>()
{
  return dave_interfaces::srv::builder::Init_Say_Response_spoken();
}

}  // namespace dave_interfaces


namespace dave_interfaces
{

namespace srv
{

namespace builder
{

class Init_Say_Event_response
{
public:
  explicit Init_Say_Event_response(::dave_interfaces::srv::Say_Event & msg)
  : msg_(msg)
  {}
  ::dave_interfaces::srv::Say_Event response(::dave_interfaces::srv::Say_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dave_interfaces::srv::Say_Event msg_;
};

class Init_Say_Event_request
{
public:
  explicit Init_Say_Event_request(::dave_interfaces::srv::Say_Event & msg)
  : msg_(msg)
  {}
  Init_Say_Event_response request(::dave_interfaces::srv::Say_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Say_Event_response(msg_);
  }

private:
  ::dave_interfaces::srv::Say_Event msg_;
};

class Init_Say_Event_info
{
public:
  Init_Say_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Say_Event_request info(::dave_interfaces::srv::Say_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Say_Event_request(msg_);
  }

private:
  ::dave_interfaces::srv::Say_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dave_interfaces::srv::Say_Event>()
{
  return dave_interfaces::srv::builder::Init_Say_Event_info();
}

}  // namespace dave_interfaces

#endif  // DAVE_INTERFACES__SRV__DETAIL__SAY__BUILDER_HPP_
