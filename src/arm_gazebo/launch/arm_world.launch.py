import os
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    urdf_file = os.path.join(get_package_share_directory('arm_description'), 'urdf', 'arm.urdf.xacro')
    controllers_file = os.path.join(get_package_share_directory('arm_gazebo'), 'config', 'arm_controllers.yaml')

    return LaunchDescription([
        ExecuteProcess(
            cmd=['gazebo', '--verbose', '-s', 'libgazebo_ros_factory.so'],
            output='screen'
        ),
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            parameters=[{'robot_description': urdf_file}]
        ),
        Node(
            package="controller_manager",
            executable="ros2_control_node",
            parameters=[urdf_file, controllers_file],
            output="screen"
        ),
    ])
