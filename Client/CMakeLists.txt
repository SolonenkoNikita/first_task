cmake_minimum_required(VERSION 3.16)
project(Client)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(Client source/Client.cpp)

target_include_directories(Client PRIVATE ${cppzmq_SOURCE_DIR})
target_include_directories(Client PRIVATE ${ZeroMQ_SOURCE_DIR}/include)

target_link_libraries(Client PUBLIC libzmq)
target_link_libraries(Client PUBLIC Students)
