cmake_minimum_required(VERSION 3.21)
project(shell C)

set(CMAKE_C_STANDARD 11)

add_executable(
        "ex/myShell.c"
        ex/shell.c)
