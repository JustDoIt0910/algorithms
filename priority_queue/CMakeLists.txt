add_executable(priority_queue priority_queue.c main.c)

target_include_directories(priority_queue PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})