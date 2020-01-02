#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <unistd.h>
#include "ros/ros.h"
#include "rosHCSR04/jetsonGPIO.h"
#include "rosHCSR04/hcsr04.h"
#include "std_msgs/Float64.h"
#include <ros/console.h>
#include <iostream>
#include <fstream>

using namespace std;

int getkey() {
    int character;
    struct termios orig_term_attr;
    struct termios new_term_attr;

    /* set the terminal to raw mode */
    tcgetattr(fileno(stdin), &orig_term_attr);
    memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
    new_term_attr.c_lflag &= ~(ECHO|ICANON);
    new_term_attr.c_cc[VTIME] = 0;
    new_term_attr.c_cc[VMIN] = 0;
    tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);
    /* read a character from the stdin stream without blocking */
    /*   returns EOF (-1) if no character is available */
    character = fgetc(stdin);
    /* restore the original terminal attributes */
    tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);
    return character;
}

int main(int argc, char **argv){
    /*Create a ROS node "talker" to capture the distance from ultrasonic sensor
     * */
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    std_msgs::Float64 Distance;
    ros::Publisher  chatter = n.advertise<std_msgs::Float64>("chatter", 1000);

    // Use gpio397 as trigger, gpio392 as echo
    HCSR04 *hcsr04 = new HCSR04();
    // Make the HC-SR04 available in user space
    hcsr04->exportGPIO() ;
    // Then set the direction of the pins
    hcsr04->setDirection() ;

    while(getkey() != 27){
        unsigned int duration = hcsr04->pingMedian(5) ; //collect the duration for avg of 5 pings
        if (duration != NO_ECHO) {
            //cout << "Duration: " << duration << " Distance (cm): " << duration/58.0 << endl ;
            Distance.data=duration/58.0;
            chatter.publish(Distance); //publish the distance
            ros::spinOnce(); //required to handle callbacks
        }
        usleep(10000); // sleep 10 milliseconds
    }
    cout << "HC-SR04 example finished." << endl;
    hcsr04->unexportGPIO() ; //unexport the gpio pins from user space
    return 0;
}


