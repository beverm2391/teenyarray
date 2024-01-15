#include <iostream>
#include <cstddef> // this is for size_t which is an unsigned integer type
#include <stdexcept> // this is for standard exceptions

//! notes ======================================================================

// ! what is vector?
// vector is a dynamic array built in the standard library
// it is a template class, which means that it can be used with different data types
// data is stored in a contiguous memory block
// handles memory management automatically

// ! memory buffer uses vector for now. why?
// 1. auto memory management
// 2. contiguous memory block
// 3. can be resized
// 4. convenient functions like push_back, pop_back, etc.

// ! code =======================================================================

template <typename T>
class Tarray {
    public:
    // constructor and so on
    Tarray(const std:vector<int>& shape) : shape(shape), offset(0), isContiguous(true), view(nullptr) {
        // TODO add bounds checking (negative dimensions, zero dimensions, etc.)
        // calcualte total size and allocate memory
        int totalSize = 1;
        for (int dim: shape) {
            totalSize *= dim;
        }
        buffer.resize(totalSize);
    }

    // accessor and other utility functions
    T& operator()(const std::vector<int> &indices) {
        // add bounds checking and calculation of offset
        // this is mostly a placeholder for multidimensional indexing
        return buffer[offset]; // placeholder
    }

    // operations

    private:
        std::vector<int> shape; // shape of the array (dim1, dim2, dim3, ...)
        std::vector<int> strides; // strides of the array (stride1, stride2, stride3, ...)
        std::string dtype; // data type of elements in the array
        std::size_t offset; // offset in the buffer
        bool isContiguous;
        Tarray* view; // pointer to the view of the array
        std::vector<T> buffer; // buffer with the actual data
};

// main function
int main() {
    return 0;
}