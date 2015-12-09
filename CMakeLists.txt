cmake_minimum_required(VERSION 3.3)
project(socks5_c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        test.c
        test.h)
add_executable(socks5_c ${SOURCE_FILES})