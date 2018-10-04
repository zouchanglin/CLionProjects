cmake_minimum_required(VERSION 3.12)
project(02_OpencvDemo)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)

add_executable(02_OpencvDemo ${SOURCE_FILES})

include_directories(/usr/local/include)

set(TARGET_LIBS
        "/usr/local/lib/libopencv_core.so"
        "/usr/local/lib/libopencv_highgui.so"
        "/usr/local/lib/libopencv_imgproc.so"
        "/usr/local/lib/libopencv_imgcodecs.so")

target_link_libraries(02_OpencvDemo ${TARGET_LIBS})