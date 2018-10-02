cmake_minimum_required(VERSION 3.11.1)
project(08_SoftAddress)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp)


add_executable(08_SoftAddress ${SOURCE_FILES})

#include_directories("C:\\\\develop\\\\opencv3.2\\\\install\\\\include")
include_directories("C:\\develop\\opencv3.2\\install\\include")

set(TARGET_LIBS
        "C:\\\\develop\\\\opencv3.2\\\\install\\\\x64\\\\mingw\\\\lib\\\\libopencv_core320.dll.a"
        "C:\\\\develop\\\\opencv3.2\\\\install\\\\x64\\\\mingw\\\\lib\\\\libopencv_highgui320.dll.a"
        "C:\\\\develop\\\\opencv3.2\\\\install\\\\x64\\\\mingw\\\\lib\\\\libopencv_imgproc320.dll.a"
        "C:\\\\develop\\\\opencv3.2\\\\install\\\\x64\\\\mingw\\\\lib\\\\libopencv_imgcodecs320.dll.a")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g -ggdb")

target_link_libraries(08_SoftAddress ${TARGET_LIBS})