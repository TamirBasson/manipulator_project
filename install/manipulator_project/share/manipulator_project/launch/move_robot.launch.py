from launch import LaunchDescription
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import IncludeLaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from moveit_configs_utils import MoveItConfigsBuilder
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():

# Path to the kinematics.yaml file
    kinematics_file_path = PathJoinSubstitution([
        get_package_share_directory('robot_moveit_config'),
        'config',
        'kinematics.yaml'
    ])

    # Node for the robot motion
    run_move_robot = Node(
        package='manipulator_project',
        executable='move_robot',
        output='screen',
        parameters=[kinematics_file_path]  # Pass substitution object, not a file directly
    )

    return LaunchDescription([

         run_move_robot
    ])