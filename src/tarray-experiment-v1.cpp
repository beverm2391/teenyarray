#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <iostream>
#include <cstddef> // this is for size_t which is an unsigned integer type
#include <vector>

namespace py = pybind11; // this is for pybind11 and is used for the PYBIND11_MODULE macro

class Tarray
{
public:
    Tarray(
        const std::vector<size_t> &shape,
        const std::vector<float> &buffer = std::vector<float>(), // Changed to actual object
        size_t offset = 0,
        const std::vector<size_t> &strides = std::vector<size_t>(), // Changed to actual object
        char order = 'C')
        : shape(shape),
          buffer(buffer.empty() ? std::vector<float>(calculateSize(shape)) : buffer),
          offset(offset),
          strides(strides.empty() ? calculateStrides(shape, order) : strides),
          order(order)
    {
        // Constructor implementation...
    }

    // util functions to get attributes and debug
    std::vector<size_t> getShape() const { return shape; }     // returns a copy of the shape
    std::vector<float> getBuffer() const { return buffer; }    // returns a copy of the buffer
    size_t getOffset() const { return offset; }                // returns a copy of the offset
    std::vector<size_t> getStrides() const { return strides; } // returns a copy of the strides
    char getOrder() const { return order; }                    // returns a copy of the order

    // ! DEBUG ====================
    void print()
    {
        std::cout << "shape = ";
        for (const auto &s : shape)
        {
            std::cout << s << ", ";
        } // range based for loop that iterates over the shape vector
        std::cout << std::endl;

        std::cout << "buffer = ";
        for (const auto &b : buffer)
        {
            std::cout << b << ", ";
        } // range based for loop that iterates over the buffer vector
        std::cout << std::endl;

        std::cout << "offset = " << offset << std::endl; // print out the offset

        std::cout << "strides = ";
        if (!strides.empty())
        { // if strides is not empty
            for (const auto &s : strides)
            {
                std::cout << s << ", ";
            }
        }
        else
        { // if strides is empty
            std::cout << "None";
        }
        std::cout << std::endl;
        std::cout << "order = " << order << std::endl; // print out the order
    }
    // ! DEBUG ====================

private:
    std::vector<size_t> shape;
    std::vector<float> buffer;
    size_t offset;
    std::vector<size_t> strides;
    char order;

    size_t calculateSize(const std::vector<size_t> &shape)
    {
        // Calculate total size needed for buffer based on shape (total number of elements)
        size_t size = 1;
        for (auto &dim : shape)
        {
            size *= dim;
        }
        return size;
    }

    std::vector<size_t> calculateStrides(const std::vector<size_t> &shape, char order)
    {
        // Calculate strides based on shape and order
        return shape; // TODO - just returning shape right now to see if it fixes the constructor issue in Python
    }
};

int main()
{
    std::vector<size_t> shape = {2, 3};
    Tarray a(shape);

    a.print(); // will print out all the attributes

    return 0;
}

PYBIND11_MODULE(teenyarray, m)
{
    py::class_<Tarray>(m, "tarray")
        .def(py::init<const std::vector<size_t> &, const std::vector<float> &, size_t, const std::vector<size_t> &, char>(),
             py::arg("shape"),
             py::arg("buffer") = std::vector<float>(),
             py::arg("offset") = 0,
             py::arg("strides") = std::vector<size_t>(),
             py::arg("order") = 'C')
        .def("getShape", &Tarray::getShape)
        .def("getBuffer", &Tarray::getBuffer)
        .def("getOffset", &Tarray::getOffset)
        .def("getStrides", &Tarray::getStrides)
        .def("getOrder", &Tarray::getOrder)
        .def("print", &Tarray::print);
}