cmake_minimum_required(VERSION 2.8)

aux_source_directory(. SRCS_DIR)
add_executable(AntiGDB ${SRCS_DIR})
