add_executable(bi_tree_test bi_tree_test.cc bi_tree.c ../stack/stack.c)

target_include_directories(bi_tree_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(bi_tree_test gtest gtest_main)

add_test(NAME bi_tree_test COMMAND bi_tree_test)