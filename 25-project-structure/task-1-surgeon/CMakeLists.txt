cmake_minimum_required(VERSION 3.30)
project("Surgeon Simulator" VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(task-1-surgeon src/main.cpp include/instruments.h)
target_include_directories(task-1-surgeon PUBLIC include)