from launch import LaunchDescription
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import IncludeLaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from moveit_configs_utils import MoveItConfigsBuilder
import os


def generate_launch_description():
    # Load MoveIt configuration for the robot
    robot_moveit_config = MoveItConfigsBuilder("robot").to_moveit_configs()

    # Robot State Publisher Node
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[robot_moveit_config.robot_description]
    )

    # Joint State Publisher Node
    joint_state_publisher = Node(
        package="joint_state_publisher",
        executable="joint_state_publisher",
        output="screen"
    )

    # # Path to the kinematics.yaml file
    # kinematics_file_path = PathJoinSubstitution([
    #     FindPackageShare('robot_moveit_config'),
    #     'config',
    #     'kinematics.yaml'
    # ])

    # # Node for the robot motion
    # run_move_robot = Node(
    #     package='manipulator_project',
    #     executable='move_robot',
    #     output='screen',
    #     parameters=[kinematics_file_path]  # Pass substitution object, not a file directly
    # )

    # Path to the MoveIt demo.launch.py file
    demo_launch = PathJoinSubstitution([
        FindPackageShare('robot_moveit_config'),
        'launch',
        'demo.launch.py'
    ])

    # Include the demo launch file
    include_demo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(demo_launch)
    )

    return LaunchDescription([
        robot_state_publisher,
        joint_state_publisher,
        include_demo_launch
        # run_move_robot
    ])
