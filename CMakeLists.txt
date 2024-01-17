cmake_minimum_required(VERSION 3.4...3.18) # specify the minimum version of CMake
project(teenyarray) # specify the name of the project

add_subdirectory(extern/pybind11)  # subdirectory containing pybind11
pybind11_add_module(teenyarray src/pybind-example.cpp)  # name of the module and source file(s)