cmake_minimum_required(VERSION 3.14)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        base64.cpp
        base64.h
        encryption.cpp
        helpers.cpp
        helpers.h
        monarch.cpp
        monarch.h
        password.cpp
        password.h
        username.cpp
        username.h)
