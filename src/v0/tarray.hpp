#ifndef TARRAY_HPP
#define TARRAY_HPP

#include <iostream>
#include <stddef.h>
#include <vector>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

template <typename T> // dtype agnostic
class Tarray {
    private:
        T* data;
        std::vector<size_t> shape;
        std::vector<size_t> strides;
        size_t size; // numel

    public:
        Tarray(std::initializer_list<size_t> shapeArgs) // constructor to allocate memory based on shape
        ~Tarray() // destructor to free memory

        T& operator()(std::initializer_list<size_t> indices) // access elements
        const T& operator()(std::initializer_list<size_t> indices) const // access elements (const version)

        // methods to get shape, strides, size, etc.

        // methods to get/set elements

        // methods to get/set slices

        // no operations here because they'll go in `tfuncc.hpp`
};

#endif

// ! Bindings ===================================================

namespace py = pybind11;

PYBIND11_MODULE(teenyarray, m) {}