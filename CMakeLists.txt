cmake_minimum_required(VERSION 3.27)
project(Project_SO1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_SO1 main.cpp
        Philosopher.cpp
        Philosopher.h
        Chopstick.cpp
        Chopstick.h
        Table.cpp
        Table.h)

set(CMAKE_EXE_LINKER_FLAGS "-static")
