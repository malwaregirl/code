CMAKE_MINIMUM_REQUIRED(VERSION 3.13)

project(template)

add_executable(template function/template_function.cpp
        class/template_class.cpp class/template_class.h)