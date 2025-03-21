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
find_package(manipulator_interfaces REQUIRED)

# Add the executable
add_executable(move_robot src/move_robot.cpp)
# Link dependencies
ament_target_dependencies(move_robot
  rclcpp
  moveit_core
  moveit_ros_planning_interface
  moveit_msgs
  geometry_msgs
  trajectory_msgs
)

# Add executable for move_to_pose_service_node
add_executable(move_to_pose_service_node src/move_to_pose_service_node.cpp)
ament_target_dependencies(move_to_pose_service_node
  rclcpp 
  moveit_core 
  moveit_ros_planning_interface 
  moveit_msgs
  geometry_msgs
  manipulator_interfaces
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


# Install the executable
install(TARGETS move_robot
  DESTINATION lib/${PROJECT_NAME})

  # Install the executable
install(TARGETS move_to_pose_service_node
DESTINATION lib/${PROJECT_NAME})


# Install directories
install(
  DIRECTORY launch urdf robot2_moveit_config 
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
