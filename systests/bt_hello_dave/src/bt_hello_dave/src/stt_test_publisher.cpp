#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <chrono>
#include <iostream>
#include <thread>

/// Simulates /stt/result message(s) for testing the Hello Dave BT
/// without needing voskros to actually recognize speech.
///
/// Usage:
///   ros2 run bt_hello_dave stt_test_publisher "<phrase>" ["<second part>"]
///
/// A single argument publishes one /stt/result message.
/// Two arguments publish two messages ~800ms apart, simulating a
/// phrase split across two recognitions.
int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("stt_test_publisher");
  auto pub = node->create_publisher<std_msgs::msg::String>("/stt/result", 10);

  if (argc < 2) {
    std::cerr << "Usage: stt_test_publisher \"<phrase>\" [\"<second part>\"]\n";
    rclcpp::shutdown();
    return 1;
  }

  // Allow publisher/subscriber discovery to settle.
  std::this_thread::sleep_for(std::chrono::milliseconds(500));

  std_msgs::msg::String msg1;
  msg1.data = argv[1];
  pub->publish(msg1);
  RCLCPP_INFO(node->get_logger(), "Published: '%s'", msg1.data.c_str());

  if (argc >= 3) {
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
    std_msgs::msg::String msg2;
    msg2.data = argv[2];
    pub->publish(msg2);
    RCLCPP_INFO(node->get_logger(), "Published: '%s'", msg2.data.c_str());
  }

  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  rclcpp::shutdown();
  return 0;
}
