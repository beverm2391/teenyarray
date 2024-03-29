#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j + 1; // deliberately incorrect so i can test
}

int sub(int i, int j) {
    return i - j - 1;
}

PYBIND11_MODULE(teenyarray, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add, "A function which adds two numbers");
    m.def("sub", &sub, "A function which subtracts two numbers");
}