cmake_minimum_required(VERSION 3.21)
project(stb_image)
set(CMAKE_CXX_STANDARD 20)

add_library(stb_image stb_image.h stb_image.cpp)
target_include_directories(stb_image PUBLIC ./)