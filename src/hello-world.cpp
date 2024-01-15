#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class MyClass {
public:
    void displayMessage() {
        std::cout << "Hello, World!" << std::endl;
    };
};

class MyClass2 {
    public:
        MyClass2(int a, int b) : x{a}, y{b} {}
    
    private:
        int x;
        int y;
};

std::vector<int> vec = {1, 2, 3, 4}; // dynamic array

// overloads the + operator for the Point class
class Point {
public:
    int x, y;

    Point operator+(const Point& p) {
        return Point{x + p.x, y + p.y};
    };
};