cmake_minimum_required(VERSION 3.14)
project(light_bird C)

set(CMAKE_C_STANDARD 99)

add_executable(light_bird main.c light-bird-sketch/light_bird.c light-bird-sketch/light_bird.h test_helpers.c test_helpers.h)