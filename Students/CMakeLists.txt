cmake_minimum_required(VERSION 3.16)
project(Students)

set(CMAKE_CXX_STANDARD 20)

add_library(Students STATIC source/Students.cpp)

target_include_directories(Students PUBLIC include)