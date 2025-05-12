cmake_minimum_required(VERSION 3.30)
project(cpp_32_json_task1)

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(cpp_32_json_task1 main.cpp)

target_link_libraries(cpp_32_json_task1 PRIVATE nlohmann_json::nlohmann_json)