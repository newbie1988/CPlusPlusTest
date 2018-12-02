cmake_minimum_required(VERSION 2.8)
project(InterceptingTest)
aux_source_directory(. SRCS_DIR)
add_executable(InterceptingTest ${SRCS_DIR})
