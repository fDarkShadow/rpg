cmake_minimum_required(VERSION 3.0)
project(rpg)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable( rpg
    ${CMAKE_SOURCE_DIR}/src/rpg.cpp
)