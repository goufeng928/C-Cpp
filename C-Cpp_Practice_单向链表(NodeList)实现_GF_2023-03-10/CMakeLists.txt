cmake_minimum_required(VERSION 3.16)
project(nodelist C)

set(CMAKE_C_STANDARD 99)

add_executable(nodelist main.c NodeList_Function.c NodeList_Function.h)