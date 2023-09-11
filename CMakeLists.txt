cmake_minimum_required(VERSION 3.6)

project(algorithm)

set(CMAKE_VERBOSE_MAKEFILE ON)
option(STACK_TEST_MODE "test stack implementation,
binary_tree can not be tested in this mode" OFF)

enable_testing()
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

include_directories(${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(queue)
add_subdirectory(priority_queue)

if (STACK_TEST_MODE)
    message(STATUS "stack module will be compiled in test mode,
    turn off STACK_TEST_MODE if you want to compile the binary_tree module")

    add_compile_definitions(STACK_ELEM=int)
    add_subdirectory(stack)
else (STACK_TEST_MODE)
    add_compile_definitions(STACK_ELEM=BiTree)
    add_subdirectory(binary_tree)
endif (STACK_TEST_MODE)

add_subdirectory(kmp)
add_subdirectory(sort)
add_subdirectory(avl)