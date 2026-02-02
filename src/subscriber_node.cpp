#include <memory>
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class SubscriberNode : public rclcpp::Node
{
public:
  SubscriberNode()
  : Node("subscriber_node")
  {
    // TODO: Create the subscription here
    // We subscribe to "/chatter" with a queue size of 10.
    // std::bind is used to link the callback function, and '_1' is a placeholder 
    // for the message argument that ROS 2 passes to the callback.
    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "/chatter",
      10,
      std::bind(&SubscriberNode::topic_callback, this, _1));
  }

private:
  // TODO: Define the topic_callback function here
  // The callback receives the message as a constant reference (const &) for efficiency.
  void topic_callback(const std_msgs::msg::String & msg) const
  {
    // Log the incoming message data
    // msg.data is a std::string, so we use .c_str() for the logger format
    RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
  }

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SubscriberNode>());
  rclcpp::shutdown();
  return 0;
}
