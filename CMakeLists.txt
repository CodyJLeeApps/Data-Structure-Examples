#####################################################
# Author:  Cody Lee
# Project: Data_Structures project to hold sub-projects
# Created: 10/02/2017
# Updated: 10/02/2017
#####################################################
cmake_minimum_required(VERSION 3.0)
project(Data_Structures)

set(LIBRARY_TYPE STATIC)

get_filename_component(PROJECT_ROOT ${CMAKE_CURRENT_BINARY_DIR} PATH)

set (CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

include(${CMAKE_MODULE_PATH}/flags.cmake)
include(${CMAKE_MODULE_PATH}/build.cmake)

#projects
include_directories("${PROJECT_SOURCE_DIR}/projects")
add_subdirectory("${PROJECT_SOURCE_DIR}/projects/linked_list")
