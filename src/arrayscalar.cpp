#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
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

	std::string repr() const {
		switch (type) {
		case DataType::Float32:
			return "Dtype(type=float32, size=4)";
		case DataType::Int32:
			return "Dtype(type=int32, size=4)";
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
	// ? these need to be bound for the getDtype method to work
    py::enum_<DataType>(m, "DataType")
        .value("Float32", DataType::Float32)
        .value("Int32", DataType::Int32)
        .export_values();

    py::class_<Dtype>(m, "Dtype")
        .def(py::init<DataType>())
        .def("getSize", &Dtype::getSize)
		.def("__str__", &Dtype::str)
		.def("__repr__", &Dtype::repr);

    // For ArrayScalar, I need to bind each specialized template
    py::class_<ArrayScalar<float>>(m, "ArrayScalarFloat32")
        .def(py::init([](float value) {
            return new ArrayScalar<float>(value, Dtype(DataType::Float32));
        }))
        .def("getValue", &ArrayScalar<float>::getValue)
        .def("getDtype", &ArrayScalar<float>::getDtype)
        .def("__str__", [](const ArrayScalar<float> &self) {
                 return std::to_string(self.getValue());
		})
        .def("__repr__", [](const ArrayScalar<float> &self) {
            return "ArrayScalarFloat32(val=" + std::to_string(self.getValue()) + ")";
        });

    py::class_<ArrayScalar<int>>(m, "ArrayScalarInt32")
        .def(py::init([](int value) {
            return new ArrayScalar<int>(value, Dtype(DataType::Int32));
        }))
        .def("getValue", &ArrayScalar<int>::getValue)
        .def("getDtype", &ArrayScalar<int>::getDtype)
        .def("__str__", [](const ArrayScalar<int> &self) {
                 return std::to_string(self.getValue());
		})
        .def("__repr__", [](const ArrayScalar<int> &self) {
            return "ArrayScalarInt32(val=" + std::to_string(self.getValue()) + ")";
        });
}