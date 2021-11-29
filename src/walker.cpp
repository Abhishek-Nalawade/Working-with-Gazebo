/**
 * MIT License

 * Copyright (c) 2021 Abhishek Nalawade

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

/**
 * @file publisher.cpp
 * @author Abhishek Nalawade
 * @brief walker file
 * @version 0.1
 * @date 2021-11-27
 *
 * @copyright Copyright (c) 2021
 */

#include"../include/walker.hpp"

// /**
//  * @brief Construct a new MoveTurtlebot object
//  */
MoveTurtlebot::MoveTurtlebot() {
  object = 0;
  velocity.linear.x = 0.2;
  velocity.linear.y = 0.0;
  velocity.linear.z = 0.0;
  std::cout << "initialized\n";
}

void MoveTurtlebot::detectObstacle(
                           const sensor_msgs::LaserScan::ConstPtr& obj) {
  int i = 0;
  // Looking for obstacle
  std::cout << "from here\n";
  while (i < obj->ranges.size()) {
    if (obj->ranges[0] <= 0.6 || obj->ranges[45] <= 0.6 ||
                                    obj->ranges[315] <= 0.6) {
      object = 1;
      return;
    }
    i++;
  }
  object = 0;
}


void MoveTurtlebot::publish(int argc, char **argv) {
  std::cout << "once\n";
  ros::Rate loop_rate(10);

  velocity_chatter = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

  distance = n.subscribe<sensor_msgs::LaserScan> ("/scan", 10,
        &MoveTurtlebot::detectObstacle, this);

  while (ros::ok()) {
    // std::cout << "obstacle " << obstacle << "\n";
    if (object) {
      ROS_INFO_STREAM("object detected!");
      std::cout << "obs detected \n";
      velocity.linear.x = 0.0;
      velocity.angular.z = 0.3;
    } else {

      ROS_INFO_STREAM("Going straight");
      velocity.angular.z = 0.0;
      velocity.linear.x = 0.2;
    }
    velocity_chatter.publish(velocity);
    ros::spinOnce();
    loop_rate.sleep();
  }
}

/**
 * @brief Destroy the MoveTurtlebot object
 */
MoveTurtlebot::~MoveTurtlebot() {
  std::cout << "Destructed\n";
}
