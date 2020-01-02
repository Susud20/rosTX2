#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"
/*
 *Listener node receives the message from the talker node and publishes it.
 */
void chatterCallback(const std_msgs::Float64::ConstPtr& msg) {
     ROS_INFO("I heard:[%f]",msg->data);
}

int main(int argc, char **argv){
     ros::init(argc, argv, "listener");
     ros::NodeHandle n;
     ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
     ros::spin();
     return 0;
}

