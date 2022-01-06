# Working-with-Gazebo
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
-------

A simple tutorial for the standard ROS cpp publisher and subscriber setup


## To Build
1) Create a catkin workspace
2) Clone the repository using

```
git clone https://github.com/Abhishek-Nalawade/Working-with-Gazebo
```

## To Run
1) Go in catkin workspace directory and type ```catkin_make clean && catkin_make```
2) ```source devel/setup.bash```
3) ```roslaunch gazebo_tutorial tutorial.launch```



## Rosbag

The rosbag recording is disabled by default.

To generate a new rosbag file type

```roslaunch beginner_tutorials tutorial.launch bagRecord:=true```

A bag file will be saved in Results directory. To play the ROS bag file, type the following in a new terminal.

cd cakin_ws/src/gazebo_tutorial/results
rosbag play bag.bag


Inspecting the bag

To inspect a recorded bag file: cd into the resutls directory where rosbags are stored and type

```rosbag info bag.bag```



## Dependencies
1) Ubuntu 18.04
2) ROS Melodic
3) roscpp
4) std_msgs
5) sensor_msgs
