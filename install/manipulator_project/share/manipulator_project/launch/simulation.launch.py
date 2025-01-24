from launch import LaunchDescription
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import IncludeLaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # Path to the demo.launch.py file
    demo_launch = PathJoinSubstitution([
        FindPackageShare('moveit_robot_config'),
        'launch',
        'demo.launch.py'
    ])

    # Include the demo launch file
    include_demo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(demo_launch)
    )

    return LaunchDescription([
        include_demo_launch
    ])