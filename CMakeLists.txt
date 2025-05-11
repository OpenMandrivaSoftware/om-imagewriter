cmake_minimum_required(VERSION 4.0)
project(OMImageWriter CXX)

find_package(Qt6 REQUIRED COMPONENTS
                  Core
                  Widgets
                  Svg
                  Linguist
)

qt_standard_project_setup()

#add_subdirectory(lang)
#add_subdirectory(img)
add_subdirectory(src)

