cmake_minimum_required(VERSION 3.16)
project(Server)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(Server source/Server.cpp)

target_include_directories(Server PRIVATE ${cppzmq_SOURCE_DIR})
target_include_directories(Server PRIVATE ${ZeroMQ_SOURCE_DIR}/include)

target_link_libraries(Server PRIVATE libzmq)
target_link_libraries(Server PUBLIC StudentsProcessor)
