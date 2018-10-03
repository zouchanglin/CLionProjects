cmake_minimum_required(VERSION 3.10)
project(06_CmakeList)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)

add_executable(06_CmakeList ${SOURCE_FILES})

include_directories(/usr/local/include)

set(TARGET_LIBS
        "/usr/local/lib/libopencv_core.so"
        "/usr/local/lib/libopencv_highgui.so"
        "/usr/local/lib/libopencv_imgproc.so"
        "/usr/local/lib/libopencv_imgcodecs.so")

target_link_libraries(06_CmakeList ${TARGET_LIBS})
