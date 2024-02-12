cmake_minimum_required(VERSION 3.27)
project(GroupChat C)

set(CMAKE_C_STANDARD 11)

add_executable(GroupChat main.c
        server/server.c
        server/server.h)
