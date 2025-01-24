import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
import xacro

#I made this file to check the URDF model in RViz
def generate_launch_description():
    # Path to the URDF/Xacro file
    pkg_path = os.path.join(get_package_share_directory('manipulator_project'))
    xacro_file = os.path.join(pkg_path, 'urdf', 'manipulator_model.urdf.xacro')

    # Parse the Xacro file into URDF
    robot_description_config = xacro.process_file(xacro_file).toxml()

    # Define parameters for robot_state_publisher
    robot_state_publisher_params = {'robot_description': robot_description_config}

    # Robot State Publisher Node
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[robot_state_publisher_params]
    )

    # Joint State Publisher Node
    joint_state_publisher = Node(
        package="joint_state_publisher",
        executable="joint_state_publisher",
        output="screen"
    )

    # RViz Node
    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        output="screen",
        arguments=["-d", os.path.join(pkg_path, "config", "urdf_config.rviz")]
    )

    return LaunchDescription([
        robot_state_publisher,
        joint_state_publisher,
        rviz_node
    ])
