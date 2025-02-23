#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>

class ArmControllerNode : public rclcpp::Node
{
public:
    ArmControllerNode() : Node("arm_controller_node")
    {
        // Create a subscription to the joint states
        joint_state_subscriber_ = this->create_subscription<sensor_msgs::msg::JointState>(
            "/joint_states", 10, std::bind(&ArmControllerNode::jointStateCallback, this, std::placeholders::_1));

        // Create a publisher to send joint position commands
        position_command_publisher_ = this->create_publisher<std_msgs::msg::Float64MultiArray>(
            "/position_controller/command", 10);
    }

private:
    // Callback function to handle joint state messages
    void jointStateCallback(const sensor_msgs::msg::JointState::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Received joint state: [%f, %f, %f, %f]",
                    msg->position[0], msg->position[1], msg->position[2], msg->position[3]);
        
        // Example: Publishing a simple joint command
        auto msg_command = std_msgs::msg::Float64MultiArray();
        msg_command.data = {1.0, 1.5, 2.0, 2.5}; // Example joint positions
        position_command_publisher_->publish(msg_command);
    }

    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_state_subscriber_;
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr position_command_publisher_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ArmControllerNode>());
    rclcpp::shutdown();
    return 0;
}
