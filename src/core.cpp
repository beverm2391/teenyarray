#include <map>
#include <stddef.h>
#include <string>

// ! Dtype ===================================================
// Dtype struct to hold metadata
struct TypeMetadata {
    size_t itemsize;
    std::string name;
    // TODO add byteorder?? might go somewhere else idk yet
    TypeMetadata(size_t itemsize, std::string name) : itemsize(itemsize), name(name) {}
};

std::map<std::string, TypeMetadata> typeRegistry = {
    {"float32", TypeMetadata(4, "float32")}, {"int32", TypeMetadata(4, "int32")}
    // TODO add more types
};

// ! Tarray ===================================================
class Tarray {
  private:
    void *data; // void pointer to allow for any data type
    std::vector<size_t> shape;
    std::vector<size_t> strides;
    size_t size;               // numel
    const TypeMetadata *dtype; // pointer to type metadata

  public:
    Tarray(const std::string &typeName, std::vector<size_t> shapeArgs) {
        // TODO (0) check if shapeArgs is valid, throw an error if not, etc.

        // (1) get the type metadata
        auto it = typeRegistry.find(typeName); // check if type exists
        if (it == typeRegistry.end()) {        // if not, throw an error
            throw std::runtime_error("Type not found in registry: " + typeName);
        }
        dtype = &it->second; // set dtype to the found type

        // TODO (2) calculate size, allocate memory, etc.
    };

    ~Tarray() {
        // free memory
    }

    size_t getItemSize() const { return dtype->itemsize; }
    std::string getTypeName() const { return dtype->name; }

    // methods to get shape, strides, size, etc.

    // util methods
    std::string str() const {
        return "this will be a string representation of the array, like in numpy or something. TODO.";
    }

    std::string repr() const { return "Tarray<Dtype=" + dtype->name + ", Size=" + std::to_string(size) + ">"; }
};

// ! Bindings ===================================================

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(teenyarray, m) {
    py::class_<Tarray>(m, "tarray")
        .def(py::init<const std::string &, std::vector<size_t>>()) // this is a vector because python sequences are
                                                                   // automatically converted to vectors
        .def_property_readonly("itemsize", &Tarray::getItemSize)
        .def_property_readonly("dtype", &Tarray::getTypeName)
        .def("__str__", &Tarray::str)
        .def("__repr__", &Tarray::repr);
}