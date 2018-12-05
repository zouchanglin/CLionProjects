cmake_minimum_required(VERSION 3.12)
project(33_msg_queue C)

set(CMAKE_C_STANDARD 99)


add_executable(server server.c comm.c comm.h)
add_executable(client client.c comm.c comm.h)