cmake_minimum_required(VERSION 2.8.3)
project(common_utilities)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(catkin REQUIRED cmake_modules COMPONENTS
  roscpp
  std_msgs
  std_srvs
  message_generation
)

add_message_files(
	DIRECTORY
	msgs
	FILES
	ControllerRequest.msg
	ControllerState.msg
    Initialize.msg
	RoboyState.msg
	Steer.msg
	Status.msg
	Trajectory.msg
)

add_service_files(
	DIRECTORY
	srvs
	FILES
	SetTrajectory.srv
	EmergencyStop.srv
	Record.srv
)

generate_messages(
	DEPENDENCIES std_msgs
)

catkin_package(CATKIN_DEPENDS message_runtime message_generation)
