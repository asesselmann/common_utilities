cmake_minimum_required(VERSION 2.8.3)
project(common_utilities)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(catkin REQUIRED cmake_modules COMPONENTS
        roscpp
        std_msgs
        std_srvs
        geometry_msgs
        message_generation
        )
include_directories(    include
                        ${catkin_INCLUDE_DIRS})
add_message_files(
        DIRECTORY
        msg
        FILES
        ControllerRequest.msg
        ControllerState.msg
        MotorStatus.msg
        MotorCommand.msg
        Pose.msg
        RoboyState.msg
        Steer.msg
        Status.msg
        Trajectory.msg
)

add_service_files(
        DIRECTORY
        srv
        FILES
        Initialize.srv
        Record.srv
        SetTrajectory.srv
        EmergencyStop.srv
)

generate_messages(
        DEPENDENCIES std_msgs std_srvs geometry_msgs
)

catkin_package( CATKIN_DEPENDS roscpp message_runtime message_generation
                INCLUDE_DIRS include)
