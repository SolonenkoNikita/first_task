cmake_minimum_required(VERSION 3.16)
project(StudentsProcessor)

set(CMAKE_CXX_STANDARD 20)

add_library(StudentsProcessor STATIC source/StudentsProcessor.cpp)

target_link_libraries(StudentsProcessor Students)

target_include_directories(StudentsProcessor PUBLIC include)