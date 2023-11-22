cmake_minimum_required(VERSION 3.15)

project(RayTracing)

set ( CMAKE_CXX_STANDARD          20 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )

file(GLOB SRC_FILES "src/*.cpp")

include_directories(src)

add_executable(rayTracing ${SRC_FILES})

target_link_libraries(rayTracing tbb)
