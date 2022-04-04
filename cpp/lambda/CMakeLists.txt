CMAKE_MINIMUM_REQUIRED(VERSION 3.13)

project(lambda)

add_executable(lambda lambda.cpp)

set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -pedantic \
        -fsanitize=address -fno-omit-frame-pointer -fsanitize-recover -O1")
