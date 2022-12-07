/*
Copyright 2022 Naveen Mangla

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/


/**
 * @brief Swat class for swat bots
 * 
 */

#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Quaternion.h>


using std::placeholders::_1;
using namespace std::chrono_literals;

using LASER = sensor_msgs::msg::LaserScan;
using TWIST = geometry_msgs::msg::Twist; 

class Swat : public rclcpp::Node {
 public:
  Swat() : Node("Swat_move"){
    auto pubTopicName = "cmd_vel";
    publisher_ = this->create_publisher<TWIST>(pubTopicName, 10);

    // Publisher callback
    auto processCallback = std::bind(&Swat::callback, this);
    timer_ = this->create_wall_timer(100ms, processCallback);};

    // auto subCallback = std::bind(&swat::subscribe_callback, this, _1);
    // auto default_qos = rclcpp::QoS(rclcpp::SensorDataQoS());
    

  void callback() {
    auto message = TWIST();
    message.linear.x =1;
    publisher_->publish(message);
    RCLCPP_INFO_STREAM(this->get_logger(), "State = FORWARD");

  
  }
//   rclcpp::Subscription<LASER>::SharedPtr subscription_;
  rclcpp::Publisher<TWIST>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
//   LASER laser_;           // laser message
//   StateType state_;       // state
//   int num_readings = 15;  // angle to check, -15 to 15
};