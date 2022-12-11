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
 * @file base.cpp
 * @author Naveen Mangla (nmangla@umd.edu)
 * @brief Functions discription for base class
 * @version 0.1
 * @date 2022-12-02
 *
 *
 */

#include <rclcpp/rclcpp.hpp>


int main(int argc, char * argv[])
{
  // init
  // rclcpp::init(argc, argv);
  // // node
  // auto node = std::make_shared<BotController>("bot_controller", "robot");
  // rclcpp::spin(node);
  // // shutdown
  // rclcpp::shutdown();

  rclcpp::executors::MultiThreadedExecutor exec;
  auto node = std::make_shared<BotController>("bot_controller", "robot");

  rclcpp::spin(std::make_shared<Threats>());
  exec.add_node(node);
  exec.spin();
  rclcpp::shutdown();
}
