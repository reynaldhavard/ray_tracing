cmake_minimum_required(VERSION 3.15)

project(RayTracing)

set ( CMAKE_CXX_STANDARD          20 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )

file(GLOB SRC_FILES "src/*.cpp")

add_executable(inOneWeekend ${SRC_FILES})
