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

#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Quaternion.h>

#include <geometry_msgs/msg/twist.hpp>
#include <iostream>
#include <nav_msgs/msg/odometry.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <utility>
#include <vector>

/**
 * @brief This is base class for swat and threat bots
 *
 */

class BaseClass {
 private:
  std::pair<const int, const int> goal1 = std::make_pair(0, 0);  // goal1
  std::pair<const int, const int> goal2 = std::make_pair(0, 0);  // goal2
  std::pair<const int, const int> goal3 = std::make_pair(0, 0);  // goal3
  std::pair<const int, const int> goal4 = std::make_pair(0, 0);  // goal4

  std::vector<std::pair<const int, const int>> goals = {
      goal1, goal2, goal3, goal4};  // vector of goals

 public:
  BaseClass() = default;  // Constructor
  void terminate();       // terminator
};