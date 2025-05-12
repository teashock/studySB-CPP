cmake_minimum_required(VERSION 3.30)
project(cpp_30_1_http)

set(CMAKE_CXX_STANDARD 17)
set(BUILD_CPR_TEST OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG dd967cb48ea6bcbad9f1da5ada0db8ac0d532c06)
FetchContent_MakeAvailable(cpr)

add_executable(cpp_30_1_http main.cpp)
target_link_libraries(cpp_30_1_http PRIVATE cpr::cpr)