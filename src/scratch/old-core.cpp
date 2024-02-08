#include <cstddef>
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <stdexcept>
#include <string>

// ! Dtype ===================================================

class Dtype {
  public:
    enum class DataType { Float32, Int32 };
    enum ByteOrder { LittleEndian, BigEndian, Native, Ignore };

  private:
    DataType type;
    int itemsize;
    ByteOrder byteorder;

  public:
    Dtype(DataType type, int itemsize, ByteOrder byteorder) : type(type), itemsize(itemsize), byteorder(byteorder) {}

    // type
    DataType getType() const { return type; }
    void setType(DataType type) { this->type = type; } // this-> is like self in python

    // itemsize
    int getItemsize() const { return itemsize; }
    void setItemsize(int itemsize) { this->itemsize = itemsize; }

    // byteorder
    // I dont think this is relevant for 8 bit data types
    ByteOrder getByteOrder() const { return byteorder; }
    void setByteOrder(ByteOrder byteorder) { this->byteorder = byteorder; }

    // equality
    // C++ is strongly typed so don't really need to validate the other argument
    bool operator==(const Dtype &other) const {
        return type == other.type && itemsize == other.itemsize && byteorder == other.byteorder;
    }

    // TODO casting will be implemented in the tfunc class i think
    // TODO come back to this later

    std::string str() const {
        switch (type) {
        case DataType::Float32:
            return "float32";
        case DataType::Int32:
            return "int32";
        default:
            throw std::runtime_error("Unsupported data type");
        }
    }

    std::string repr() const {
        std::string byteorder_str;
        switch (byteorder) {
        case ByteOrder::LittleEndian:
            byteorder_str = "little";
            break;
        case ByteOrder::BigEndian:
            byteorder_str = "big";
            break;
        case ByteOrder::Native:
            byteorder_str = "native";
            break;
        case ByteOrder::Ignore:
            byteorder_str = "ignore";
            break;
        default:
            throw std::runtime_error("Unsupported byte order");
        }

        return "Dtype(" + str() + ", " + std::to_string(itemsize) + ", " + byteorder_str + ")";
    };
};

// ! Tarray ==================================================

template <typename T> // dtype agnostic
class Tarray {
  public:
    Tarray(const std::vector<size_t> &shape, const std::string &dtype = "float32")
        : shape(shape), offset(0), isContiguous(true), view(nullptr) {
        // TODO add bounds checking (negative dimensions, zero dimensions, etc.)

        // calcualte total size and allocate memory
        size = 1;
        for (auto dim : shape) {
            size *= dim;
        }
        buffer.resize(size);

        // calculate strides
        calculateStrides();
    }

    // indexing operator
    T& operator()(const std::vector<int> &indices) {
        // add bounds checking and calculation of offset
        // this is mostly a placeholder for multidimensional indexing
        return buffer[offset]; // placeholder
    }

    // shape operations
    reshape() {} // make sure to handle impossible reshapes
    transpose() {}    

    // static operations
    std:size_t getSize() const {
        return size;
    }

    const std::vector<int>& getShape() const {
        return shape;
    }

    private:
        std::vector<int> shape; // shape of the array (dim1, dim2, dim3, ...)
        std::vector<int> strides; // strides of the array (stride1, stride2, stride3, ...)
        std::string dtype; // data type of elements in the array
        std::size_t size; // total size of the array
        std::size_t offset; // offset in the buffer
        bool isContiguous;
        Tarray* view; // pointer to the view of the array
        std::vector<T> buffer; // buffer with the actual data

    void calculateStrides() {
    }    
};

// ! Bindings =================================================

namespace py = pybind11;

PYBIND11_MODULE(teenyarray, m) {
    py::class_<Dtype>(m, "Dtype")
        // This logic seems kind of hacky but it works
        // TODO move this into a factory function or something
        .def(py::init([](std::string type) {
            if (type == "float32") {
                return Dtype(Dtype::DataType::Float32, 4, Dtype::ByteOrder::Native);
            } else if (type == "int32") {
                return Dtype(Dtype::DataType::Int32, 4, Dtype::ByteOrder::Native);
            } else {
                throw std::runtime_error("Unsupported data type");
            }
        }))
        // TODO this will throw
        // ? TypeError: Unable to convert function return value to a Python type!
        // .def_property_readonly("type", &Dtype::getType) // def_readonly threw some weight error so i switched to
        // def_property_readonly
        .def_property_readonly("itemsize", &Dtype::getItemsize)
        // TODO this also throws the same error
        // .def_property_readonly("byteorder", &Dtype::getByteOrder)
        .def("__str__", &Dtype::str)
        .def("__repr__", &Dtype::repr);
}