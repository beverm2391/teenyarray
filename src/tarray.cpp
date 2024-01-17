#include <iostream>
#include <cstddef> // this is for size_t which is an unsigned integer type
#include <stdexcept> // this is for standard exceptions

//! c++ notes ======================================================================
// ! what is vector?
// vector is a dynamic array built in the standard library
// it is a template class, which means that it can be used with different data types
// data is stored in a contiguous memory block
// handles memory management automatically

// const means that the function does not modify the object
// size_t is an unsigned integer type meaning that it can only store positive values

// ! Design chocies ==============================================================
// ! memory buffer uses vector for now. why?
// 1. auto memory management
// 2. contiguous memory block
// 3. can be resized
// 4. convenient functions like push_back, pop_back, etc.

// ! on strides
// Strides are the number of elements you need to skip in memory to move one element along a dimension.

// should my stride be the number of bytes or the number of elements? (i dont have an itemsize attribute yet)

// ! memory layout
// I've decided on row-major (C-style) memory layout for now
// this means that the last dimension is contiguous in memory
// (this is the default layout in C and C++)

// ! code =======================================================================

template <typename T> // currently a template class which is dtype agnostic, might need a way to access at runtime
class Tarray {
    public:
    //! constructor
    // modify this to init strides and offset based on shape
    Tarray(const std:vector<int>& shape) : shape(shape), offset(0), isContiguous(true), view(nullptr) {
        // TODO add bounds checking (negative dimensions, zero dimensions, etc.)
        
        // calcualte total size and allocate memory
        size = 1;
        for (auto dim: shape) {
            size *= dim;
        }
        buffer.resize(size);

        // calculate strides
        calculateStrides();
    }

    // ! indexing operator
    T& operator()(const std::vector<int> &indices) {
        // add bounds checking and calculation of offset
        // this is mostly a placeholder for multidimensional indexing
        return buffer[offset]; // placeholder
    }

    // ! shape operations
    reshape() {} // make sure to handle impossible reshapes
    transpose() {}    

    // ! static operations
    
    // ! expose private attributes
    std:size_t getSize() const {
        return size;
    }

    const std::vector<int>& getShape() const { // returns a reference 
        return shape;
    }

    private:
        std::vector<int> shape; // shape of the array (dim1, dim2, dim3, ...)
        std::vector<int> strides; // strides of the array (stride1, stride2, stride3, ...)
        std::string dtype; // data type of elements in the array
        std::size_t size; // total size of the array
        std::size_t offset; // offset in the buffer
        bool isContiguous;
        Tarray* view; // pointer to the view of the array
        std::vector<T> buffer; // buffer with the actual data

    void calculateStrides() {
    }
};

// main function
int main() {
    return 0;
}