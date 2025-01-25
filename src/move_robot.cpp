#include <memory>
#include <thread>
#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>

int main(int argc, char *argv[])
{
  // Initialize ROS
  rclcpp::init(argc, argv);

  // Create the Node
  auto const node = std::make_shared<rclcpp::Node>(
      "hello_moveit",
      rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));

  // Create a ROS logger
  auto const logger = rclcpp::get_logger("hello_moveit");

  // Create the MoveIt MoveGroup Interface
  using moveit::planning_interface::MoveGroupInterface;
  auto move_group_interface = MoveGroupInterface(node, "arm");

    // Set the planning frame to "world"
  move_group_interface.setPoseReferenceFrame("world");
   // Confirm the planning frame
  RCLCPP_INFO(logger, "Planning frame set to: %s", move_group_interface.getPlanningFrame().c_str());


  // Create a separate executor for spinning the node
  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(node);

  // Start a separate thread for spinning
  std::thread spin_thread([&executor]() {
    executor.spin();
  });

  // Set a target pose
  auto const target_pose = [] {
    geometry_msgs::msg::Pose msg;
    msg.position.x = 0.4;
    msg.position.y = 0.0;
    msg.position.z = 0.5;
    msg.orientation.x = 0.0;
    msg.orientation.y = 0.707;
    msg.orientation.z = 0.0;
    msg.orientation.w = 0.707;
    return msg;
  }();
  move_group_interface.setApproximateJointValueTarget(target_pose, "end_effector");
  
  // Create a plan to that target pose
  auto const [success, plan] = [&move_group_interface] {
    moveit::planning_interface::MoveGroupInterface::Plan msg;
    auto const ok = static_cast<bool>(move_group_interface.plan(msg));
    return std::make_pair(ok, msg);
  }();

  // Execute the plan
  if (success)
  {
    move_group_interface.execute(plan);
    RCLCPP_INFO(logger, "Plan executed successfully.");
    RCLCPP_INFO(logger, "Planning frame: %s", move_group_interface.getPlanningFrame().c_str());
    RCLCPP_INFO(logger, "Target pose: x=%f, y=%f, z=%f",
    target_pose.position.x,
    target_pose.position.y,
    target_pose.position.z);

  }
  else
  {
    RCLCPP_ERROR(logger, "Planning failed!");
  }

  auto current_pose = move_group_interface.getCurrentPose("end_effector");
  RCLCPP_INFO(logger, "Current pose after execution: x=%f, y=%f, z=%f",
    current_pose.pose.position.x,
    current_pose.pose.position.y,
    current_pose.pose.position.z);

  // Shutdown the executor and thread
  executor.cancel();
  spin_thread.join();

  // Shutdown ROS
  rclcpp::shutdown();
  return 0;
}
