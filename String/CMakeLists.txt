cmake_minimum_required (VERSION 2.8)

project(string)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(String String.cpp String.h String_test.cpp)

target_link_libraries(String ${GTEST_BOTH_LIBRARIES})
target_link_libraries(String ${CMAKE_THREAD_LIBS_INIT})
add_test(Test String)
enable_testing()