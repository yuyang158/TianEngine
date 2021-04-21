cmake_minimum_required(VERSION 3.19)

project(Foundation)

set(CMAKE_CXX_STANDARD 17)
list(APPEND SRC
        IncludeAll.cpp
        Time/Time.cpp
        Basic/RTTI.cpp)

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    list(APPEND SRC Time/Win/TimeWin.cpp)
endif()


add_library(Foundation STATIC ${SRC})
target_include_directories(Foundation PUBLIC ./)
