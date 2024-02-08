#include <cstring> // for memcpy
#include <map>
#include <stddef.h>
#include <stdexcept>
#include <string>
#include <vector>

// ! Dtype ===================================================
// Dtype struct to hold metadata
struct TypeMetadata {
    size_t itemsize;
    std::string name;
    // TODO add byteorder?? might go somewhere else idk yet
    TypeMetadata(size_t itemsize, std::string name) : itemsize(itemsize), name(name) {}
};

// ! Type Registry ===================================================
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
    std::string order; // memory layout (C or F, default is C)

  public:
    Tarray(const std::string &typeName, std::vector<size_t> shapeArgs, const std::string &orderArg = "C")
        : shape(shapeArgs), dtype(&typeRegistry.at(typeName)), order(orderArg) { // use at() to throw an Index error if type not found
        // TODO (0) check if shapeArgs is valid, throw an error if not, etc.
        // (1) calculate size
        size = 1;
        for (auto &dim : shape) {
            size *= dim;
        }
        // (2) allocate memory
        data = new (std::nothrow) char[size * dtype->itemsize]; // allocate memory for the array (numel * itemsize)
        if (!data) { // if nullptr still (using nothrow to return nullptr, then using a custom error message)
            throw std::runtime_error("Memory allocation failed.");
        }
        // ? since data is a void pointer, we allocate memory for char (1 byte) and then cast it to the proper type
        // TODO (3) calculate strides
    };

    ~Tarray() {
        delete[] static_cast<char *>(data); // cast to chat* for proper deletion
    }

    // getters
    size_t getSize() const { return size; }
    std::vector<size_t> getShape() const { return shape; }
    std::string getDtypeName() const { return dtype->name; }
    size_t getItemSize() const { return dtype->itemsize; }
    std::string getOrder() const { return order; }

    // setters
    void setShape(std::vector<size_t> newShape) { // TODO add checks for new shape, stride calculation, etc.
        shape = newShape;
    }
    void setOrder(std::string newOrder) { // Change the parameter type to std::string
        order = newOrder;
        // TODO Change all the strides and stuff
    }

    // data setters
    template <typename T>
    void fillWithValue(const T& value) {
        // fills an instantiated array (that has a shape and dtype) with a single value
        if (dtype->name != typeid(T).name()) {
            throw std::runtime_error("Type mismatch."); // TODO handle automatic casting
        }

        for (size_t i = 0; i < size; ++i) { // TODO get this faster than O(n)?
            std::memcpy(static_cast<char*>(data) + i * dtype->itemsize, &value, dtype->itemsize);
        }
    }

    // fill sequence
    template <typename T>
    void fillWithValues(const std::vector<T>& values) {
        // fills an instantiated array (that has a shape and dtype) with a sequence of values
        if (dtype->name != typeid(T).name()) {
            throw std::runtime_error("Type mismatch."); // TODO handle automatic casting
        }

        if (values.size() != size) {
            throw std::runtime_error("Size mismatch."); // TODO handle resizing??
        }

        for (size_t i = 0; i < size; ++i) {
            std::memcpy(static_cast<char*>(data) + i * dtype->itemsize, &values[i], dtype->itemsize);
        }
    }

    // TODO fill with random

    // TODO ones (make it from the fill method)

    // static methods
    template <typename T>
    static Tarray fill(const T& value, const std::string& typeName, const std::vector<size_t>& shape) {
        // takes a single value and instantiates, then fills the array with that value
        // TODO auto infer type from T
        Tarray arr(typeName, shape);
        arr.fillWithValue(value);
        return arr;
    }

    static Tarray zeros(const std::string& typeName, const std::vector<size_t>& shape) {
        Tarray arr(typeName, shape);
        arr.fillWithValue(0);
        return arr;
    }

    static Tarray ones(const std::string& typeName, const std::vector<size_t>& shape) {
        Tarray arr(typeName, shape);
        arr.fillWithValue(1);
        return arr;
    }

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
    m.doc() = "A teeny-tiny array library for Python.";
    py::class_<Tarray>(m, "tarray")
        .def(py::init<const std::string &, std::vector<size_t>>()) // this is a vector because python sequences are
                                                                   // automatically converted to vectors
        .def_property_readonly("itemsize", &Tarray::getItemSize)
        .def_property_readonly("dtype", &Tarray::getDtypeName)
        .def_property("shape", &Tarray::getShape, &Tarray::setShape)
        .def_property_readonly("size", &Tarray::getSize)
        .def_static("zeros", &Tarray::zeros)
        .def("__str__", &Tarray::str)
        .def("__repr__", &Tarray::repr);
}