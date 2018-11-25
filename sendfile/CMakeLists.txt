cmake_minimum_required(VERSION 2.8)
project(SystemCallTest)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(./)
aux_source_directory(. SRCS_DIR)
add_executable(SystemCallTest ${SRCS_DIR})
