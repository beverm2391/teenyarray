#include <pybind11/pybind11.h>
#include <string>

// ! Data types ===================================================
enum class DataType { Float32, Int32 }; // enum

class Dtype {
public:
  DataType type;

  Dtype(DataType t) : type(t) {}

  size_t getSize() const {
    switch (type) {
    case DataType::Float32:
      return 4;
    case DataType::Int32:
      return 4;
    default:
      throw std::runtime_error("Unsupported data type");
    }
  }

  std::string str() const {
    switch (type) {
    case DataType::Float32:
      return "Dtype(float32)";
    case DataType::Int32:
      return "Dtype(int32)";
    default:
      throw std::runtime_error("Unsupported data type");
    }
  }
};

// ! ArrayScalar =================================================
template <typename T> class ArrayScalar {
  T value;
  Dtype dtype;

public:
  ArrayScalar(T val, Dtype dt) : value(val), dtype(dt) {}

  T getValue() const { return value; }
  Dtype getDtype() const { return dtype; }

  // TODO add more methods
  // type compatibility
  // casting
  // validating arguments??
  // arithmetic operations
};

// ! Pybind ========================================================

namespace py = pybind11;

PYBIND11_MODULE(teenyarray, m) {
  py::enum_<DataType>(m, "DataType") // optionally expose the enum
      .value("Float32", DataType::Float32)
      .value("Int32", DataType::Int32)
      .export_values();

  py::class_<Dtype>(m, "Dtype")
      .def(py::init<DataType>())
      .def("getSize", &Dtype::getSize)
      .def("__str__", &Dtype::str); // __str__ is the magic method for str()

  // For ArrayScalar, I need to bind each specialized template
  py::class_<ArrayScalar<float>>(m, "ArrayScalarFloat32")
      .def(py::init<float, Dtype>())
      .def("getValue", &ArrayScalar<float>::getValue)
      .def("getDtype", &ArrayScalar<float>::getDtype);

  py::class_<ArrayScalar<int>>(m, "ArrayScalarInt32")
      .def(py::init<int, Dtype>())
      .def("getValue", &ArrayScalar<int>::getValue)
      .def("getDtype", &ArrayScalar<int>::getDtype);
}