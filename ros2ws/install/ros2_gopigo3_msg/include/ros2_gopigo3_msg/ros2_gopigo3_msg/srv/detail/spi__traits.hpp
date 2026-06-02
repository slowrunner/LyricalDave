// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_gopigo3_msg:srv/SPI.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros2_gopigo3_msg/srv/spi.hpp"


#ifndef ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__TRAITS_HPP_
#define ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "ros2_gopigo3_msg/srv/detail/spi__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros2_gopigo3_msg
{

namespace srv
{

inline void to_flow_style_yaml(
  const SPI_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: data_out
  {
    if (msg.data_out.size() == 0) {
      out << "data_out: []";
    } else {
      out << "data_out: [";
      size_t pending_items = msg.data_out.size();
      for (auto item : msg.data_out) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SPI_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data_out
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data_out.size() == 0) {
      out << "data_out: []\n";
    } else {
      out << "data_out:\n";
      for (auto item : msg.data_out) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SPI_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, ros2_gopigo3_msg::srv::SPI_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).data_out);
}

}  // namespace srv

}  // namespace ros2_gopigo3_msg

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<ros2_gopigo3_msg::srv::SPI_Request>()
{
  return "ros2_gopigo3_msg::srv::SPI_Request";
}

template<>
constexpr const char * name<ros2_gopigo3_msg::srv::SPI_Request>()
{
  return "ros2_gopigo3_msg/srv/SPI_Request";
}

template<>
struct has_fixed_size<ros2_gopigo3_msg::srv::SPI_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_gopigo3_msg::srv::SPI_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_gopigo3_msg::srv::SPI_Request>
  : std::true_type {};

template<>
struct MessageTraits<ros2_gopigo3_msg::srv::SPI_Request>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "data_out",
  };
};

}  // namespace rosidl_generator_traits

namespace ros2_gopigo3_msg
{

namespace srv
{

inline void to_flow_style_yaml(
  const SPI_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: data_in
  {
    if (msg.data_in.size() == 0) {
      out << "data_in: []";
    } else {
      out << "data_in: [";
      size_t pending_items = msg.data_in.size();
      for (auto item : msg.data_in) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SPI_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data_in
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data_in.size() == 0) {
      out << "data_in: []\n";
    } else {
      out << "data_in:\n";
      for (auto item : msg.data_in) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SPI_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, ros2_gopigo3_msg::srv::SPI_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).data_in);
}

}  // namespace srv

}  // namespace ros2_gopigo3_msg

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<ros2_gopigo3_msg::srv::SPI_Response>()
{
  return "ros2_gopigo3_msg::srv::SPI_Response";
}

template<>
constexpr const char * name<ros2_gopigo3_msg::srv::SPI_Response>()
{
  return "ros2_gopigo3_msg/srv/SPI_Response";
}

template<>
struct has_fixed_size<ros2_gopigo3_msg::srv::SPI_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_gopigo3_msg::srv::SPI_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_gopigo3_msg::srv::SPI_Response>
  : std::true_type {};

template<>
struct MessageTraits<ros2_gopigo3_msg::srv::SPI_Response>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "data_in",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace ros2_gopigo3_msg
{

namespace srv
{

inline void to_flow_style_yaml(
  const SPI_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SPI_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SPI_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, ros2_gopigo3_msg::srv::SPI_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace srv

}  // namespace ros2_gopigo3_msg

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<ros2_gopigo3_msg::srv::SPI_Event>()
{
  return "ros2_gopigo3_msg::srv::SPI_Event";
}

template<>
constexpr const char * name<ros2_gopigo3_msg::srv::SPI_Event>()
{
  return "ros2_gopigo3_msg/srv/SPI_Event";
}

template<>
struct has_fixed_size<ros2_gopigo3_msg::srv::SPI_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_gopigo3_msg::srv::SPI_Event>
  : std::integral_constant<bool, has_bounded_size<ros2_gopigo3_msg::srv::SPI_Request>::value && has_bounded_size<ros2_gopigo3_msg::srv::SPI_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<ros2_gopigo3_msg::srv::SPI_Event>
  : std::true_type {};

template<>
struct MessageTraits<ros2_gopigo3_msg::srv::SPI_Event>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "info",
    "request",
    "response",
  };
};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<ros2_gopigo3_msg::srv::SPI>()
{
  return "ros2_gopigo3_msg::srv::SPI";
}

template<>
constexpr const char * name<ros2_gopigo3_msg::srv::SPI>()
{
  return "ros2_gopigo3_msg/srv/SPI";
}

template<>
struct has_fixed_size<ros2_gopigo3_msg::srv::SPI>
  : std::integral_constant<
    bool,
    has_fixed_size<ros2_gopigo3_msg::srv::SPI_Request>::value &&
    has_fixed_size<ros2_gopigo3_msg::srv::SPI_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros2_gopigo3_msg::srv::SPI>
  : std::integral_constant<
    bool,
    has_bounded_size<ros2_gopigo3_msg::srv::SPI_Request>::value &&
    has_bounded_size<ros2_gopigo3_msg::srv::SPI_Response>::value
  >
{
};

template<>
struct is_service<ros2_gopigo3_msg::srv::SPI>
  : std::true_type
{
};

template<>
struct is_service_request<ros2_gopigo3_msg::srv::SPI_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros2_gopigo3_msg::srv::SPI_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__TRAITS_HPP_
