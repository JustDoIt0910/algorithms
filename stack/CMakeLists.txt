add_executable(stack_test stack_test.cc stack.c)

target_include_directories(stack_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(stack_test gtest gtest_main)

add_test(NAME stack_test COMMAND stack_test)