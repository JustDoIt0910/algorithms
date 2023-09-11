cmake_minimum_required(VERSION 2.8)

project(algorithm)

set(CMAKE_VERBOSE_MAKEFILE ON)


enable_testing()
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

include_directories(${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(avl)
add_subdirectory(priority_queue)
add_subdirectory(kmp)
add_subdirectory(sort)
add_subdirectory(queue)
add_subdirectory(binary_tree)