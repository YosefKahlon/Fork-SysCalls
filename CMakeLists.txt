cmake_minimum_required(VERSION 3.16)
project(Fork_SysCalls)

set(CMAKE_C_STANDARD 11)

add_executable(Fork_SysCalls shell.c server.c)
