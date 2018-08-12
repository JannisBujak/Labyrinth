cmake_minimum_required(VERSION 3.12)
project(Labyrinth)

set(CMAKE_CXX_STANDARD 14)

add_executable(Labyrinth main.cpp source/Labyrinth.cpp source/Labyrinth.h source/Field.cpp source/Field.h source/Way.cpp source/Way.h source/Position.cpp source/Position.h)