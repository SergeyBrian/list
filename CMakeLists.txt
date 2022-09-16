cmake_minimum_required(VERSION 3.21)
project(list C)

set(CMAKE_C_STANDARD 99)

add_executable(list list.c tests/tests.c tests/test_list.h tests/test_list.c)
