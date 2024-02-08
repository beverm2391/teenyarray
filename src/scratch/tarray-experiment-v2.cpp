#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <iostream>
#include <cstddef> // this is for size_t which is an unsigned integer type
#include <vector>
#include <tuple>

namespace py = pybind11; // this is for pybind11 and is used for the PYBIND11_MODULE macro