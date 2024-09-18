#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <rclcpp/rclcpp.hpp>
#include <visualization_msgs/msgs/marker.hpp>

using namespace std::chrono_literals;

class markerPublisher : public rclcpp::Node
{
    public:
        markerPublisher()
        : Node("markerPublisher"), count(0)
        {
            publisher_ = this->create_publisher<visualization_msgs::msgMarker("Visualization_marker", 10);

            timer_ = this->create_wall_timer(
            500ms, std::bind(&markerPublisher::time_callback, this));
        }
    private:
        void timer_callback(){
            auto message = visualization_msgs::msg::Marker();
            message.header.frame_id = "map";
            message.header.stamp = this->now();
            message.ns = "basic_shapes";
            message.type = visualization_msgs::msg::Marker::CUBE;
            message.action = visualization_msgs::msg::Marker::ADD;
            message.pose.position.x = 0.0;
            message.pose.position.y = 0.0;
            message.pose.position.z = 0.0;
            message.pose.orientation.x = 0.0;
            message.pose.orientation.y = 0.0;
            message.pose.orientation.z = 0.0;
            message.pose.orientation.w = 1.0;
            message.scale.x = 1.0;
            message.scale.y = 1.0;
            message.scale.z = 1.0;
            message.color.r = 1.0f;
            message.color.g = 0.0f;
            message.color.b = 0.0f;
            message.color.a = 1.0;
            publisher_->publish(message);
            count_++;
        }
        rclcpp::TimerBase::SharedPtr timer_;
        

}   