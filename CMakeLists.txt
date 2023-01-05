cmake_minimum_required(VERSION 2.8)

project(algorithm)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(avl)
add_subdirectory(priority_queue)
add_subdirectory(kmp)