#include <iostream>
#include <cstddef> // this is for size_t which is an unsigned integer type

class Point {
public:
    int x, y;
    Point(int a, int b) {
        x = a;
        y = b;
    }
};

class MyClass {
    public:
        explicit MyClass(int a) {}
};

void function (MyClass a) {}

int main() {
    Point p1(1, 2); // init the point class with x = 1 and y = 2
    return 0;
}
