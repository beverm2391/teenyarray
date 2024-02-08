// Function Overriding occurs when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden.

#include <iostream>

using namespace std;

class Animal {
    public:
        string color = "Black";
};

class Dog : public Animal { // inherits publicly from Animal
    public:
        string color = "Grey";
};

int main() {
    Animal d = Dog(); // initialize d as a Dog - invokes slicing where the Dog part of d is sliced off
    cout << d.color << endl; // Black

    Dog e;
    cout << e.color << endl; // Grey
    return 0;
}