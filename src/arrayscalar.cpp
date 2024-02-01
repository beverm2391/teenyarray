#include <string>
#include <pybind11/pybind11.h>

enum class DataType
{
    float32,
    float64,
    // int8,
    // int16,
    int32,
    // int64,
    // uint8, 
    // uint16,
    // uint32,
    // uint64,
    // bool_,
    // complex64,
    // complex128
};

class Dtype
{
private:
    DataType type;
    size_t size; // size in bytes

public:
    Dtype(DataType type, size_t size) : type(type), size(size) {}

    DataType getType() const { return type; }
    size_t getSize() const { return size; }

    // TODO add more methods
};

class ArrayScalar
{
    private:
    double value;
    Dtype dtype;

    public:
        ArrayScalar(double value, Dtype dtype) : value(value), dtype(dtype) {}

        double getValue() const { return value; }
        Dtype getDtype() const { return dtype; }

        // TODO add more methods
};



namespace py = pybind11;

PYBIND11_MODULE(teenyarray, m) {
    py::class_<Dtype>(m, "Dtype")
        .def(py::init<std::string, size_t>())
        .def("getName", &Dtype::getName)
        .def("getSize", &Dtype::getSize);
        // TODO add more methods

    py::class_<ArrayScalar>(m, "ArrayScalar")
        .def(py::init<double, Dtype>())
        .def("getValue", &ArrayScalar::getValue)
        .def("getDtype", &ArrayScalar::getDtype);
        // TODO add more methods
}
