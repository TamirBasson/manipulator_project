#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/msg/display_robot_state.hpp>
#include <moveit_msgs/msg/display_trajectory.hpp>
#include <moveit_msgs/msg/attached_collision_object.hpp>
#include <moveit_msgs/msg/collision_object.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <chrono>
#include <thread>

int main(int argc, char **argv)
{
    // Initialize ROS 2
    rclcpp::init(argc, argv);

    // Create a node
    auto node = rclcpp::Node::make_shared("move_group");

    // Create an asynchronous spinner to handle callbacks
    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(node);
    std::thread spinner_thread([&executor]() {
        RCLCPP_DEBUG(rclcpp::get_logger("rclcpp"), "Spinner thread started.");
        executor.spin();
    });

    // Sleep to allow time for everything to initialize
    std::this_thread::sleep_for(std::chrono::seconds(2));
    RCLCPP_INFO(node->get_logger(), "Node and spinner initialized.");

    // Move group interface for the robot arm
    RCLCPP_DEBUG(node->get_logger(), "Creating MoveGroupInterface for 'arm'.");
    moveit::planning_interface::MoveGroupInterface move_group(node, "arm");

    // Planning scene interface
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

    // Publisher for visualizing plans in RViz
    auto display_publisher = node->create_publisher<moveit_msgs::msg::DisplayTrajectory>(
        "/move_group/display_planned_path", rclcpp::QoS(10).transient_local());

    moveit_msgs::msg::DisplayTrajectory display_trajectory;

    // Log reference frames
    RCLCPP_INFO(node->get_logger(), "Reference frame: %s", move_group.getPlanningFrame().c_str());
    RCLCPP_INFO(node->get_logger(), "End effector link: %s", move_group.getEndEffectorLink().c_str());

    // Instead of setting a full pose (with orientation),
    // we only set the position target. Orientation is ignored.
    double target_x = 0;
    double target_y = 0.4;
    double target_z = 0.55;
    RCLCPP_INFO(node->get_logger(),
                "Setting position target to: x=%.2f, y=%.2f, z=%.2f",
                target_x, target_y, target_z);
    move_group.setPositionTarget(target_x, target_y, target_z);

    // Plan to the position target
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    auto success = move_group.plan(my_plan);

    // Check if planning succeeded
    if (success == moveit::core::MoveItErrorCode::SUCCESS)
    {
        RCLCPP_INFO(node->get_logger(), "Planning succeeded, moving the arm.");
        move_group.move();
    }
    else
    {
        RCLCPP_WARN(node->get_logger(), "Planning failed, not moving the arm.");
    }

    // Shutdown the spinner and ROS 2
    RCLCPP_INFO(node->get_logger(), "Shutting down node and spinner...");
    executor.cancel();           // Stop the executor
    spinner_thread.join();       // Join the spinner thread
    rclcpp::shutdown();          // Properly shut down ROS 2
    RCLCPP_INFO(node->get_logger(), "Node and spinner shut down. Exiting program.");

    return 0;
}
