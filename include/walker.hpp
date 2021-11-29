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
 * @brief walker header file
 * @version 0.1
 * @date 2021-11-27
 *
 * @copyright Copyright (c) 2021
 */
#pragma once

#include<ros/ros.h>
#include<sensor_msgs/LaserScan.h>
#include<geometry_msgs/Twist.h>
#include<iostream>

/**
 * @brief MoveTurtlebot class that contains methods to move the Turtlebot
 * @param int object check for obstacles
 * @param Twist velocity object to publish
 */
class MoveTurtlebot{
 public:
  MoveTurtlebot();
  void detectObstacle(const sensor_msgs::LaserScan::ConstPtr& obj);
  void publish(int argc, char **argv);
  ~MoveTurtlebot();
 private:
  int object;
  ros::NodeHandle n;
  ros::Publisher velocity_chatter;
  ros::Subscriber distance;
  geometry_msgs::Twist velocity;
};
