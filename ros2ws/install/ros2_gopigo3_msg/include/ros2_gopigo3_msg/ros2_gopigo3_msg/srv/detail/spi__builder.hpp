// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_gopigo3_msg:srv/SPI.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros2_gopigo3_msg/srv/spi.hpp"


#ifndef ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__BUILDER_HPP_
#define ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_gopigo3_msg/srv/detail/spi__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_gopigo3_msg
{

namespace srv
{

namespace builder
{

class Init_SPI_Request_data_out
{
public:
  Init_SPI_Request_data_out()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_gopigo3_msg::srv::SPI_Request data_out(::ros2_gopigo3_msg::srv::SPI_Request::_data_out_type arg)
  {
    msg_.data_out = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_gopigo3_msg::srv::SPI_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_gopigo3_msg::srv::SPI_Request>()
{
  return ros2_gopigo3_msg::srv::builder::Init_SPI_Request_data_out();
}

}  // namespace ros2_gopigo3_msg


namespace ros2_gopigo3_msg
{

namespace srv
{

namespace builder
{

class Init_SPI_Response_data_in
{
public:
  Init_SPI_Response_data_in()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_gopigo3_msg::srv::SPI_Response data_in(::ros2_gopigo3_msg::srv::SPI_Response::_data_in_type arg)
  {
    msg_.data_in = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_gopigo3_msg::srv::SPI_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_gopigo3_msg::srv::SPI_Response>()
{
  return ros2_gopigo3_msg::srv::builder::Init_SPI_Response_data_in();
}

}  // namespace ros2_gopigo3_msg


namespace ros2_gopigo3_msg
{

namespace srv
{

namespace builder
{

class Init_SPI_Event_response
{
public:
  explicit Init_SPI_Event_response(::ros2_gopigo3_msg::srv::SPI_Event & msg)
  : msg_(msg)
  {}
  ::ros2_gopigo3_msg::srv::SPI_Event response(::ros2_gopigo3_msg::srv::SPI_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_gopigo3_msg::srv::SPI_Event msg_;
};

class Init_SPI_Event_request
{
public:
  explicit Init_SPI_Event_request(::ros2_gopigo3_msg::srv::SPI_Event & msg)
  : msg_(msg)
  {}
  Init_SPI_Event_response request(::ros2_gopigo3_msg::srv::SPI_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SPI_Event_response(msg_);
  }

private:
  ::ros2_gopigo3_msg::srv::SPI_Event msg_;
};

class Init_SPI_Event_info
{
public:
  Init_SPI_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SPI_Event_request info(::ros2_gopigo3_msg::srv::SPI_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SPI_Event_request(msg_);
  }

private:
  ::ros2_gopigo3_msg::srv::SPI_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_gopigo3_msg::srv::SPI_Event>()
{
  return ros2_gopigo3_msg::srv::builder::Init_SPI_Event_info();
}

}  // namespace ros2_gopigo3_msg

#endif  // ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__BUILDER_HPP_
