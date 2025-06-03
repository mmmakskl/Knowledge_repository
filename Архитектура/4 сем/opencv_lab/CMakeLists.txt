cmake_minimum_required(VERSION 3.12)
project(OpenCV_Test)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED COMPONENTS core highgui videoio imgproc)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(video_capture main.cpp)
target_link_libraries(video_capture ${OpenCV_LIBS})