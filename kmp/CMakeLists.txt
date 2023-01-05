add_executable(kmp kmp\(algo4\).c main.c kmp.c)

target_include_directories(kmp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})