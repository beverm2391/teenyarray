#ifndef TARRAY_HPP
#define TARRAY_HPP

#include <iostream>
#include <stddef.h>
#include <vector>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

template <typename Dtype> // dtype agnostic
class Tarray {};

#endif

// ! Bindings ===================================================

namespace py = pybind11;

PYBIND11_MODULE(teenyarray, m) {}