# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target ros2_gopigo3_msg::ros2_gopigo3_msg
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${ros2_gopigo3_msg_TARGETS}.
if(ros2_gopigo3_msg_TARGETS AND NOT TARGET ros2_gopigo3_msg::ros2_gopigo3_msg)
  add_library(ros2_gopigo3_msg::ros2_gopigo3_msg INTERFACE IMPORTED)
  set_target_properties(ros2_gopigo3_msg::ros2_gopigo3_msg PROPERTIES
    INTERFACE_LINK_LIBRARIES "${ros2_gopigo3_msg_TARGETS}")
endif()
