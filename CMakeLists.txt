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
	ControllerState.msg
	InitializeRequest.msg
	InitializeResponse.msg
	Status.msg
	Steer.msg
	Trajectory.msg
)

generate_messages(
	DEPENDENCIES std_msgs
)

catkin_package(CATKIN_DEPENDS message_runtime)
