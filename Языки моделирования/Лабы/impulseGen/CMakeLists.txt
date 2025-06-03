cmake_minimum_required(VERSION 3.10)
project(ImpulseGenSystemC)

set(CMAKE_CXX_STANDARD 17)

# Укажи путь к установленной библиотеке SystemC
set(SYSTEMC_HOME "$ENV{HOME}/systemc/install")

include_directories(${SYSTEMC_HOME}/include)
link_directories(${SYSTEMC_HOME}/lib-linux64)

add_executable(impulse_gen
    src/main.cpp
    src/ImpulseGen.cpp
    src/ImpulseGenTest.cpp
)

target_link_libraries(impulse_gen systemc)
