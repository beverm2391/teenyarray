#ifndef DTYPES_HPP
#define DTYPES_HPP

#include <cstddef>
#include <iostream>
#include <string>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// ! Dtype ===================================================

class DtypeAbstract {
    public:
        virtual ~DtypeAbstract() {} // virtual destructor
        virtual void convertType(DtypeAbstract *newtype) = 0; // define a pure virtual function

        enum ByteOrder { LittleEndian, BigEndian, Native, Ignore };

        // str and repr
        virtual std::string str() const = 0;
        virtual std::string repr() const = 0;

    private:
        ByteOrder byteorder;

    public:
        // these methods expose the private byteorder variable to the derived classes
        ByteOrder getByteOrder() const { return byteorder; } // I dont think this is relevant for 8 bit data types
        void setByteOrder(ByteOrder byteorder) { this->byteorder = byteorder; }

        // util func to get the byte order as a string for the repr method
        std::string getByteOrderStr() const {
            switch (byteorder) {
                case ByteOrder::LittleEndian:
                    return "little";
                case ByteOrder::BigEndian:
                    return "big";
                case ByteOrder::Native:
                    return "native";
                case ByteOrder::Ignore:
                    return "ignore";
                default:
                    throw std::runtime_error("Unsupported byte order");
            }
        }
};

class Float32 : public DtypeAbstract {
    public:
        static constexpr size_t itemsize = 4; // constexpr is like const but for compile time

        void convertType(DtypeAbstract* newtype) override {
            // TODO implement this
        }

        static size_t getItemSize() {
            return itemsize;
        }

        std::string str() const override {
            return "float32";
        }

        std::string repr() const override {
            return "Dtype(type=" + str() + ", itemsize=" + std::to_string(itemsize) + ", byteorder=" + getByteOrderStr() + ")";
        }
};

class Int32 : public DtypeAbstract {
    public:
        static constexpr size_t itemsize = 4; // constexpr is like const but for compile time

        void convertType(DtypeAbstract* newtype) override {
            // TODO implement this
        }

        static size_t getItemSize() {
            return itemsize;
        }

        std::string str() const override {
            return "int32";
        }

        std::string repr() const override {
            return "Dtype(type=" + str() + ", itemsize=" + std::to_string(itemsize) + ", byteorder=" + getByteOrderStr() + ")";
        }
};

//? have to define these outside of the class to avoid "symbol not found in namespace" error in Python
constexpr size_t Float32::itemsize;
constexpr size_t Int32::itemsize;

#endif

// ! Bindings ===================================================

namespace py = pybind11;

PYBIND11_MODULE(teenyarray, m) {

    py::module_ dtypes = m.def_submodule("dtypes", "Dtype classes");

    py::class_<Float32>(dtypes, "Float32")
        .def(py::init<>())
        // ? not exposing these for now
        // .def("getByteOrder", &Float32::getByteOrder)
        // .def("setByteOrder", &Float32::setByteOrder)
        .def("__str__", &Float32::str)
        .def("__repr__", &Float32::repr)
        .def_readonly_static("itemsize", &Float32::itemsize);

    py::class_<Int32>(dtypes, "Int32")
        .def(py::init<>())
        // ? not exposing these for now
        // .def("getByteOrder", &Int32::getByteOrder)
        // .def("setByteOrder", &Int32::setByteOrder)
        .def("__str__", &Int32::str)
        .def("__repr__", &Int32::repr)
        .def_readonly_static("itemsize", &Int32::itemsize);
}