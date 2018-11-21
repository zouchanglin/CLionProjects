cmake_minimum_required(VERSION 3.12)
project(32_code C)

set(CMAKE_C_STANDARD 99)

add_executable(client client.c comm.h comm.c)
add_executable(server server.c comm.h comm.c)
