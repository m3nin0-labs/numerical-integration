cmake_minimum_required(VERSION 3.1)
project(nintegration)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-sign-compare -std=c++14")

find_package(xtl REQUIRED)
find_package(xtensor REQUIRED)

add_executable(nintegration src/main.cpp src/riemann.cpp src/trapezoidal.cpp)

target_link_libraries(nintegration xtensor)