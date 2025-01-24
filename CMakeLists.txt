cmake_minimum_required(VERSION 3.8)
project(manipulator_project)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(moveit_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(trajectory_msgs REQUIRED)

# Add the executable
add_executable(move_group src/move_group.cpp)
# Link dependencies
ament_target_dependencies(move_group
  rclcpp
  moveit_core
  moveit_ros_planning_interface
  moveit_msgs
  geometry_msgs
  trajectory_msgs
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


# Install the executable
install(TARGETS move_group
  DESTINATION lib/${PROJECT_NAME})


# Install directories
install(
  DIRECTORY config launch urdf 
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
