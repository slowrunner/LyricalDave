cmake_minimum_required(VERSION 3.8)
project(bt_hello_dave)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(behaviortree_cpp REQUIRED)
find_package(behaviortree_ros2 REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(voskros REQUIRED)
find_package(dave_interfaces REQUIRED)
find_package(yaml-cpp REQUIRED)

include_directories(include)

# ---------------------------------------------------------------------------
# Plugin library: all custom BT nodes
# ---------------------------------------------------------------------------
add_library(bt_hello_dave_nodes SHARED
  src/match_grammar_node.cpp
  src/stt_queue_nodes.cpp
  src/stt_result_subscriber_node.cpp
  src/battery_state_subscriber_node.cpp
  src/say_service_node.cpp
  src/set_grammar_node.cpp
  src/delay_seconds_node.cpp
  src/dispatch_nodes.cpp
  src/register_nodes.cpp
)

target_link_libraries(bt_hello_dave_nodes PUBLIC
  rclcpp::rclcpp
  rclcpp_lifecycle::rclcpp_lifecycle
  behaviortree_cpp::behaviortree_cpp
  behaviortree_ros2::behaviortree_ros2
  std_msgs::std_msgs
  std_srvs::std_srvs
  voskros::voskros
  dave_interfaces::dave_interfaces
  yaml-cpp::yaml-cpp
)

# ---------------------------------------------------------------------------
# Main lifecycle executable
# ---------------------------------------------------------------------------
add_executable(hello_dave_lifecycle_node
  src/hello_dave_lifecycle_node.cpp
)

target_link_libraries(hello_dave_lifecycle_node PUBLIC
  bt_hello_dave_nodes
  rclcpp::rclcpp
  rclcpp_lifecycle::rclcpp_lifecycle
  behaviortree_cpp::behaviortree_cpp
  behaviortree_ros2::behaviortree_ros2
  std_msgs::std_msgs
  std_srvs::std_srvs
  voskros::voskros
  dave_interfaces::dave_interfaces
  yaml-cpp::yaml-cpp
)

# ---------------------------------------------------------------------------
# Test STT publisher
# ---------------------------------------------------------------------------
add_executable(stt_test_publisher
  src/stt_test_publisher.cpp
)

target_link_libraries(stt_test_publisher PUBLIC
  rclcpp::rclcpp
  std_msgs::std_msgs
)

# ---------------------------------------------------------------------------
# Install
# ---------------------------------------------------------------------------
install(TARGETS
  bt_hello_dave_nodes
  hello_dave_lifecycle_node
  stt_test_publisher
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include
)

install(DIRECTORY config/
  DESTINATION share/${PROJECT_NAME}/config
)

install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

install(DIRECTORY scripts/
  DESTINATION share/${PROJECT_NAME}/scripts
  USE_SOURCE_PERMISSIONS
)

ament_package()
