add_executable(queue queue.c main.c)

target_include_directories(queue PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})