cmake_minimum_required(VERSION 2.8)
project(WheelMaker)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# 引入子目录
ADD_SUBDIRECTORY(Hash/v1)
ADD_SUBDIRECTORY(Hash/v2)
ADD_SUBDIRECTORY(String)