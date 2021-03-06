cmake_minimum_required(VERSION 2.8)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(
    /usr/local/include/opencv4
    ${CMAKE_SOURCE_DIR}/rknn_api/include
)

set(link_libs  /usr/local/lib/libopencv_core.so
               /usr/local/lib/libopencv_highgui.so
               /usr/local/lib/libopencv_imgcodecs.so
               /usr/local/lib/libopencv_imgproc.so
		       /usr/local/lib/libopencv_videoio.so
               ${CMAKE_SOURCE_DIR}/rknn_api/lib64/librknn_api.so
               pthread
)

#add_executable(rknn_mobilenet  rknn_mobilenet.cpp)
#target_link_libraries(rknn_mobilenet ${link_libs})

add_executable(rknn_ssd  rknn_ssd_multi.cpp)
target_link_libraries(rknn_ssd ${link_libs})
