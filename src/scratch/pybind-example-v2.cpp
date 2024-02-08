#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11; // this is for pybind11 and is used for the PYBIND11_MODULE macro

// tiny class to test some stuff
class TestArray {
public:
    TestArray(const std::vector<size_t> &shape) : shape(shape) {} // returns a referece (which uses the original variable) instead of a copy
    std::vector<size_t> getShape() const {return shape;} // returns a copy of the shape
private:
    std::vector<size_t> shape;
};

PYBIND11_MODULE(pybindtest, m) { // module name
    py::class_<TestArray>(m, "testarray") // class name
        .def(py::init<const std::vector<size_t>&>()) 
        .def("getShape", &TestArray::getShape);
}