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
 * @file threats.cpp
 * @author Mahima Arora (marora1@umd.edu)
 * @brief Functions discription for threat class
 * @version 0.1
 * @date 2022-12-02
 *
 * @copyright Copyright (c) 2022 Mahima Arora
 */

#include <threats.hpp>

/**
 * @brief Move threats to secure hostages
 *
 */
void Threats::callback()
{
  auto message = TWIST();

  message.angular.z = 0.1;
  publisher_->publish(message);
  count_++;

  if (count_ > 3) {exit(EXIT_SUCCESS);}

  // std::string fromFrameRel = target_frame_.c_str();
  // std::string toFrameRel = "odom";
  //   try {
  //       geometry_msgs::msg::TransformStamped t;
  //       t = tf_buffer_->lookupTransform(
  //         toFrameRel, fromFrameRel,
  //         tf2::TimePointZero);
  //         RCLCPP_INFO(this->get_logger(),"Transformation is
  //         %f",t.transform.translation.x);

  //     } catch (const tf2::TransformException & ex) {
  //       RCLCPP_INFO(
  //         this->get_logger(), "Could not transform %s to %s: %s",
  //         toFrameRel.c_str(), fromFrameRel.c_str(), ex.what());

  //       return;
  //     }

  RCLCPP_INFO_STREAM(this->get_logger(), "State = FORWARD");

  // TODO(Mahima Arora): Transformations are not well defined
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<Threats>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
