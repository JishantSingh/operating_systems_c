cmake_minimum_required(VERSION 3.20)
project(playground_c C)

set(CMAKE_C_STANDARD 11)

add_executable(playground_c main.c programs/rough.h chapter3/zombie_child.h chapter3/pid_manager.h chapter3/collatz_conjecture.h chapter3/string_reverse.h chapter3/copy_file.h chapter4/test_pid_manager.h)

target_link_libraries(playground_c rt pthread)
