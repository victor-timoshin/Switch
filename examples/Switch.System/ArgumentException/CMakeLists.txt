cmake_minimum_required(VERSION 3.2)

project(ArgumentException)
find_package(Switch REQUIRED)
add_executable(ArgumentException ArgumentException.cpp)
target_link_libraries(ArgumentException Switch.System)
