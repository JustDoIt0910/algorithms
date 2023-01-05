add_executable(sort merge_sort.c main.c)

target_include_directories(sort PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})