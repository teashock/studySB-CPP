cmake_minimum_required(VERSION 3.14)
project(38_2_html LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        WebEngineWidgets
  REQUIRED)

add_executable(38_2_html main.cpp)

target_link_libraries(38_2_html
        Qt5::Core
        Qt5::Gui
        Qt5::WebEngineWidgets
        Qt5::Widgets
)
