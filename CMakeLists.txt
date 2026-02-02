cmake_minimum_required(VERSION 3.8)
project(ros2_subscriber)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# TODO: Add the executable target named 'subscriber_node'

# 1. Add executable using src/subscriber_node.cpp
add_executable(subscriber_node src/subscriber_node.cpp)

# 2. Add dependencies (ament_target_dependencies) for rclcpp and std_msgs
ament_target_dependencies(subscriber_node rclcpp std_msgs)

# 3. Install the target to the DESTINATION lib/${PROJECT_NAME}
install(TARGETS
  subscriber_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
