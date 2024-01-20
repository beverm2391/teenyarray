#include <iostream>
#include <cstddef> // this is for size_t which is an unsigned integer type
#include <vector>

class Tarray {
public:
    Tarray(
        const std::vector<size_t> &shape, // this is a reference to a vector of size_t
        std::vector<float>* buffer = nullptr, // this is a pointer to a vector of floats (the * means pointer)
        size_t offset = 0, // this is a size_t which is an unsigned integer type (it can only be positive)
        std::vector<size_t>* strides = nullptr, // this is a pointer to a vector of size_t
        char order = 'C') // this is a char
    : shape(shape),
    buffer(buffer ? *buffer : std::vector<float>(calculateSize(shape))), // this is a ternary operator which if buffer is not null then it will use the buffer otherwise it will create a new vector of floats
    offset(offset), // the offset is the offset in the buffer (for indexing)
    strides(strides ? *strides : std::vector<size_t>()), // will take strides as an argument otherwise create an empty vector of size_t
    order(order) // defaults to column major (C)
    {
        // this is the constructor
        // TODO add bounds checking (negative dimensions, zero dimensions, etc.)
        // TODO add strides calculation
    }

// util functions to get attributes and debug
    std::vector<size_t> getShape() const {return shape;} // returns a copy of the shape
    std::vector<float> getBuffer() const {return buffer;} // returns a copy of the buffer
    size_t getOffset() const {return offset;} // returns a copy of the offset
    std::vector<size_t> getStrides() const {return strides;} // returns a copy of the strides
    char getOrder() const {return order;} // returns a copy of the order

void print() {
    std::cout << "shape = ";
    for (const auto& s : shape) { std::cout << s << ", "; } // range based for loop that iterates over the shape vector
    std::cout << std::endl; 

    std::cout << "buffer = ";
    for (const auto& b : buffer) { std::cout << b << ", "; } // range based for loop that iterates over the buffer vector
    std::cout << std::endl;

    std::cout << "offset = " << offset << std::endl; // print out the offset

    std::cout << "strides = ";
    if (!strides.empty()) { // if strides is not empty
        for (const auto& s : strides) { 
            std::cout << s << ", ";
        }
    } else { // if strides is empty
        std::cout << "None";
    }
    std::cout << std::endl;
    std::cout << "order = " << order << std::endl; // print out the order
}

private:
    std::vector<size_t> shape;
    std::vector<float> buffer;
    size_t offset;
    std::vector<size_t> strides;
    char order;

    size_t calculateSize(const std::vector<size_t>& shape) {
        // Calculate total size needed for buffer based on shape (total number of elements)
        size_t size = 1;
        for (auto& dim : shape) {
            size *= dim;
        }
        return size;
    }
};

int main() {
    std::vector<size_t> shape = {2, 3};
    Tarray a(shape);

    a.print(); // will print out all the attributes

    return 0;
}