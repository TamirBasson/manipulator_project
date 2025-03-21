from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory
import os
import yaml

def load_yaml(package_name, file_path):
    """
    Load a YAML file from a package's shared directory.
    """
    package_share_directory = get_package_share_directory(package_name)
    yaml_file_path = os.path.join(package_share_directory, file_path)
    with open(yaml_file_path, 'r') as file:
        return yaml.safe_load(file)

def generate_launch_description():
    # Load kinematics YAML
    kinematics_yaml = load_yaml("robot2_moveit_config", "config/kinematics.yaml")
    robot_description_kinematics = {"robot_description_kinematics": kinematics_yaml}

    # Node for the robot motion
    run_move_robot = Node(
        package='manipulator_project',      
        executable='move_robot',      
        output='screen',
            parameters=[
        robot_description_kinematics,  # Pass the parsed YAML as a parameter dictionary
        {"use_sim_time": True}]      
    )

    return LaunchDescription([
        run_move_robot
    ])
