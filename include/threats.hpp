
/*
Copyright 2022 Mahima Arora

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
 * @brief Threat class for threat bots
 * 
 */
#pragma once

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <std_msgs/msg/bool.hpp>
#include <geometry_msgs/msg/quaternion.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <string>
#include "tf2/exceptions.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
# include <base.hpp> // for base class

using std::placeholders::_1;
using namespace std::chrono_literals;

using LASER = sensor_msgs::msg::LaserScan;
using TWIST = geometry_msgs::msg::Twist; 

class Threats: public rclcpp::Node {
    public:
    Threats() : Node("threats_move") {
    target_frame_ = this->declare_parameter<std::string>("target_frame", "base_footprint");
    auto pubTopicName = "cmd_vel";
    publisher_ = this->create_publisher<TWIST>(pubTopicName, 10);
    
    auto processCallback = std::bind(&Threats::callback, this);
    timer_ = this->create_wall_timer(100ms, processCallback);

    tf_buffer_ =
    std::make_unique<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ =
    std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
    };

    void callback();

    ////////////////////////////////////////
    // member variables
    ////////////////////////////////////////
    rclcpp::Publisher<TWIST>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    std::shared_ptr<tf2_ros::TransformListener> tf_listener_{nullptr};
    std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
    geometry_msgs::msg::Transform current_loc;
    std::string target_frame_;
    std::string from_frame_;

};
    // 20 bots are controlled by controller
    // 1. have control for each robot
    // central controller tf frame - 20 published on tf frames
    // dynamicsally pub their pose 
    // give prefix /t1/cmd_vel --> remap 