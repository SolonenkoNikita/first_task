cmake_minimum_required (VERSION 3.20)

project (Task)
 
include(FetchContent)


FetchContent_Declare(
	ZeroMQ
	GIT_REPOSITORY https://github.com/zeromq/libzmq.git
	GIT_TAG master
)

FetchContent_MakeAvailable(ZeroMQ) 

FetchContent_Declare(
  cppzmq
  GIT_REPOSITORY https://github.com/zeromq/cppzmq.git
)


FetchContent_MakeAvailable(cppzmq)

add_subdirectory(Students)
 
add_subdirectory(StudentsProcessor)

add_subdirectory(Server)

add_subdirectory(Client)