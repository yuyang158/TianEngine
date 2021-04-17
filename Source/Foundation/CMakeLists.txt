cmake_minimum_required(VERSION 3.19)

project(Foundation)

set(CMAKE_CXX_STANDARD 17)
include_directories(Time)
include_directories(Basic)

list(APPEND SRC Time/Time.cpp)

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    # list(APPEND SRC Win/Time_win32.cpp)
endif()


add_library(Foundation STATIC ${SRC})
target_include_directories(Foundation PUBLIC ./)
