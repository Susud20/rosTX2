# Obstacle detection using ROS on JetsonTX2

An academic project to interface a HCSR04 distance sensor to the NVIDIA Jetson TX2 for obstacle detection.

Echo signal - gpio392

Trigger signal - gpio397

# Prerequisites
Flashing the JetsonTX2 - https://gitlab-pages.idial.institute/panorama.gsoc.project/rover.doc/content/installation.html

# Installation
Install ROS-melodic for Ubuntu 18.04 - [melodic/Installation/Ubuntu - ROS Wiki](http://wiki.ros.org/melodic/Installation/Ubuntu)

Setup your catkin workspace - [catkin/Tutorials/create_a_workspace - ROS Wiki](https://wiki.ros.org/catkin/Tutorials/create_a_workspace)

Build using CMakeLists.txt and package.xml files

# Description:
Utilised the simplified C++ library to interface with the NVIDIA Jetson TX2 Development Kit GPIO pins. ([GitHub - MengHuanLee/jetsonTX2GPIO](https://github.com/MengHuanLee/jetsonTX2GPIO.git))

talker.cpp -> ros node that publishes the obstacle distance(in cm)

listener.cpp -> ros node that subscribes to the talker node and prints out the distance

# Commands to run:
roscore

rosrun rosHCSR04 talker

rosrun rosHCSR04 listener

# Authors
Supriya Sudarshan - supriya.sudarshan001@stud.fh-dortmund.de

Bheeshmaraya Bheemasamudra Vruksharaj - bheeshmaraya.bheemasamudravruksharaj001@stud.fh-dortmund.de
