cmake_minimum_required(VERSION 2.8.3)
project(rosHCSR04)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

## Generate added messages and services with any dependencies listed here
generate_messages(
   DEPENDENCIES
   std_msgs
 )

###################################
## catkin specific configuration ##
###################################

catkin_package(
   INCLUDE_DIRS include
   LIBRARIES rosHCSR04
   CATKIN_DEPENDS roscpp rospy std_msgs
   DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(include ${catkin_INCLUDE_DIRS})
 install(DIRECTORY include/${PROJECT_NAME}/
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
   FILES_MATCHING PATTERN "*.h"
   PATTERN ".svn" EXCLUDE
 )

#############
## Testing ##
#############

add_executable(talker src/talker.cpp src/jetsonGPIO.c src/hcsr04.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker rosHCSR04_generate_messages_cpp)
add_executable(listener src/listener.cpp )
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener rosHCSR04s_generate_messages_cpp)
                                                                                                                            1,1        Anfang

