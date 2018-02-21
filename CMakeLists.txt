cmake_minimum_required(VERSION 3.6)
project(project_name)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(SOURCE_FILES main.c)

add_executable(project_name ${SOURCE_FILES})
target_link_libraries(project_name m)