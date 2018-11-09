cmake_minimum_required(VERSION 2.8)
project(AutoTest)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

aux_source_directory(. SRCS_DIR)
add_executable(AutoTest ${SRCS_DIR})
