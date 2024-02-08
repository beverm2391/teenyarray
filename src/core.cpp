#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>

// ! Dtype ===================================================

class Dtype {
public:
    enum class DataType { Float32, Int32 };
    enum ByteOrder { LittleEndian, BigEndian };

private:
    DataType type;
    int size;
    ByteOrder byteorder;

public:
    Dtype(DataType type, int size, ByteOrder byteorder)
        : type(type), size(size), byteorder(byteorder) {}

    // type
    DataType geType() const { return type; }
    void setType(DataType type) { this->type = type; } // this-> is like self in python
    
    // size
    int getSize() const { return size; }
    void setSize(int size) { this->size = size; }

    // byteorder
    ByteOrder getByteOrder() const { return byteorder; }
    void setByteOrder(ByteOrder byteorder) { this->byteorder = byteorder; }

    // str
    std::string str() const {
        std::string type_str;
        switch (type) {
        case DataType::Float32:
            type_str = "float32";
            break;
        case DataType::Int32:
            type_str = "int32";
            break;
        default:
            throw std::runtime_error("Unsupported data type");
        }

        std::string byteorder_str;
        switch (byteorder) {
        case ByteOrder::LittleEndian:
            byteorder_str = "little";
            break;
        case ByteOrder::BigEndian:
            byteorder_str = "big";
            break;
        default:
            throw std::runtime_error("Unsupported byte order");
        }

        return "Dtype(" + type_str + ", " + std::to_string(size) + ", " + byteorder_str + ")";
    };
};

// ! Bindings =================================================

namespace py = pybind11;

PYBIND11_MODULE(core, m) {
    py::class_<Dtype>(m, "Dtype")
        .def(py::init<Dtype::DataType, int, Dtype::ByteOrder>())
        .def_property_readonly("type", &Dtype::geType) // def_readonly threw some weight error so i switched to def_property_readonly
        .def_property_readonly("size", &Dtype::getSize)
        .def_property_readonly("byteorder", &Dtype::getByteOrder)
        .def("__str__", &Dtype::str)
        .def("__repr__", &Dtype::str);
}