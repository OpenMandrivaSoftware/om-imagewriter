cmake_minimum_required(VERSION 4.0)
project(OMImageWriter 
                  VERSION 2.7.0 
                  LANGUAGES CXX
                  DESCRIPTION "Tool for creating bootable Linux installation USB flash drives"                  
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS
                  Core
                  Widgets
                  Svg
                  Linguist
)

qt_standard_project_setup()

add_subdirectory(src)

