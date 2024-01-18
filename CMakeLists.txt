cmake_minimum_required(VERSION 3.4...3.18) # specify the minimum version of CMake
project(teenyarray) # specify the name of the project

# specify the C++ standard (11++) which is required for pybind11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(extern/pybind11)  # subdirectory containing pybind11
pybind11_add_module(teenyarray src/pybind-example.cpp)  # name of the module and source file(s)