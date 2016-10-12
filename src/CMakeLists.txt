cmake_minimum_required(VERSION 3.5)
project(RSA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    exception.h
    fileIO.cpp
    fileIO.h
    main.cpp
    Makefile
    rsa.cpp
    rsa.h)

set(BOOST_ROOT "/usr/local/Cellar/boost/1.61.0_1")

find_package(Boost 1.61.0)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

add_executable(RSA ${SOURCE_FILES})