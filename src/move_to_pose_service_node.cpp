#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>

// This is the generated header from srv/MoveToPose.srv
#include "manipulator_interfaces/srv/move_to_pose.hpp"

// Class representing the MoveToPoseService node
class MoveToPoseService : public rclcpp::Node
{
public:
  // Constructor for the node
  MoveToPoseService() 
  : Node("move_to_pose_service_node")
  {
    // Create the ROS 2 service for handling move-to-pose requests
    service_ = this->create_service<manipulator_interfaces::srv::MoveToPose>(
      "move_to_pose",
      std::bind(&MoveToPoseService::handle_move_to_pose, this,
                std::placeholders::_1, std::placeholders::_2)
    );

    RCLCPP_INFO(this->get_logger(), "Node initialized. Waiting for MoveGroupInterface initialization.");
  }

  // Initialize the MoveGroupInterface after the node is fully constructed
  void initialize_move_group()
  {
    RCLCPP_DEBUG(this->get_logger(), "Initializing MoveGroupInterface...");
    // The MoveGroupInterface allows planning and execution of motion for a specific planning group
    move_group_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(
      shared_from_this(), // This is safe because the node is already managed by a shared_ptr
      "arm"
    );

    // Set the reference frame for the robot's motion
    move_group_->setPoseReferenceFrame("world");

    RCLCPP_INFO(this->get_logger(), "MoveGroupInterface successfully initialized for planning group 'arm'.");
    RCLCPP_DEBUG(this->get_logger(), "Pose reference frame set to: %s", move_group_->getPoseReferenceFrame().c_str());
  }

private:
  // Callback function for handling service requests
  void handle_move_to_pose(
    const std::shared_ptr<manipulator_interfaces::srv::MoveToPose::Request> request,
    std::shared_ptr<manipulator_interfaces::srv::MoveToPose::Response> response)
  {
    RCLCPP_INFO(this->get_logger(), "Received request to move to a new pose.");

    // Check if MoveGroupInterface is initialized
    if (!move_group_)
    {
      RCLCPP_ERROR(this->get_logger(), "MoveGroupInterface is not initialized!");
      response->success = false;
      return;
    }

    // Extract the target pose from the service request
    geometry_msgs::msg::Pose target_pose = request->target_pose;

    // Log the requested target pose
    RCLCPP_DEBUG(this->get_logger(), "Target Pose: Position [x: %.2f, y: %.2f, z: %.2f], Orientation [x: %.2f, y: %.2f, z: %.2f, w: %.2f]",
                 target_pose.position.x, target_pose.position.y, target_pose.position.z,
                 target_pose.orientation.x, target_pose.orientation.y, target_pose.orientation.z, target_pose.orientation.w);

    // Set the target pose for the robot's end effector
    RCLCPP_DEBUG(this->get_logger(), "Setting target pose for end effector...");
    move_group_->setApproximateJointValueTarget(target_pose, "end_effector");

    // Plan the motion
    RCLCPP_INFO(this->get_logger(), "Planning motion...");
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    bool success = (move_group_->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);
    if (!success)
    {
      RCLCPP_ERROR(this->get_logger(), "Planning failed! Unable to generate a valid motion plan.");
      response->success = false;
      return;
    }
    RCLCPP_INFO(this->get_logger(), "Motion plan generated successfully.");

    // Execute the motion plan
    RCLCPP_INFO(this->get_logger(), "Executing motion...");
    auto execution_result = move_group_->execute(plan);
    success = (execution_result == moveit::core::MoveItErrorCode::SUCCESS);
    if (!success)
    {
      RCLCPP_ERROR(this->get_logger(), "Execution failed! Unable to complete the motion plan.");
      response->success = false;
      return;
    }

    RCLCPP_INFO(this->get_logger(), "Motion planned and executed successfully.");
    response->success = true;
  }

  // ROS 2 service object
  rclcpp::Service<manipulator_interfaces::srv::MoveToPose>::SharedPtr service_;

  // MoveGroupInterface object for handling motion planning
  std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);

  //Create the node as a shared pointer
  auto node = std::make_shared<MoveToPoseService>();

  // Initialize the MoveGroupInterface AFTER the node is fully constructed
  node->initialize_move_group();

  // Spin the node to process incoming requests
  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}
