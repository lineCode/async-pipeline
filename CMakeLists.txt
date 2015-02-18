project(pipeline)

cmake_minimum_required(VERSION 2.8)

######################
# Modulos a compilar #
######################

#Incluyo el root para no andar haciendo "../blah/"
include_directories(${CMAKE_SOURCE_DIR})

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 ")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3 ")

add_subdirectory(pipeline)
add_subdirectory(example)
