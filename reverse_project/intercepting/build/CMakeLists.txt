cmake_minimum_required(VERSION 2.8)

aux_source_directory(../src SRCS_DIR)
add_library(hack SHARED  ${SRCS_DIR})
