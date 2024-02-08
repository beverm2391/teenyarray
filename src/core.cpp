#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
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
    Dtype(DataType type, int itemsize, ByteOrder byteorder)
        : type(type), itemsize(itemsize), byteorder(byteorder) {}

    // type
    DataType getType() const { return type; }
    void setType(DataType type) {
        this->type = type;
    } // this-> is like self in python

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
        return type == other.type && itemsize == other.itemsize &&
               byteorder == other.byteorder;
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

        return "Dtype(" + str() + ", " + std::to_string(itemsize) + ", " +
               byteorder_str + ")";
    };
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
        // .def_property_readonly("type", &Dtype::getType) // def_readonly threw some weight error so i switched to def_property_readonly
        .def_property_readonly("itemsize", &Dtype::getItemsize)
        // TODO this also throws the same error
        // .def_property_readonly("byteorder", &Dtype::getByteOrder)
        .def("__str__", &Dtype::str)
        .def("__repr__", &Dtype::repr);
}