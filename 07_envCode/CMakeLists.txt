cmake_minimum_required(VERSION 3.10)
project(07_envCode)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)

add_executable(07_envCode ${SOURCE_FILES})

include_directories(/usr/local/include)

set(TARGET_LIBS
        "/usr/local/lib/libopencv_core.so"
        "/usr/local/lib/libopencv_highgui.so"
        "/usr/local/lib/libopencv_imgproc.so"
        "/usr/local/lib/libopencv_imgcodecs.so")


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g -ggdb")
target_link_libraries(07_envCode ${TARGET_LIBS})


