cmake_minimum_required(VERSION 3.20)
project(lab2_main)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab2_main main.cpp _gets.h prints.cpp prints.h)

include_directories(../lab2_lib)

target_link_libraries(lab2_main lab2_lib m)