cmake_minimum_required(VERSION 3.10)
project(ZeroCounterSystemC)

set(CMAKE_CXX_STANDARD 17)
set(SYSTEMC_HOME "$ENV{HOME}/systemc/install")

include_directories(${SYSTEMC_HOME}/include)
link_directories(${SYSTEMC_HOME}/lib-linux64)

file(GLOB SRCS
    src/ZeroCounter.cpp
    src/ZeroCounterTest.cpp
    src/main.cpp
)

add_executable(zero_counter ${SRCS})
target_link_libraries(zero_counter systemc)
