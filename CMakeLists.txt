cmake_minimum_required(VERSION 3.17)
project(live_world)

set(CMAKE_CXX_STANDARD 14)

add_executable(live_world main.cpp)
add_executable(test_sword sword.cpp)
add_executable(test_character character.cpp)