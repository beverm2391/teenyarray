// A virtual function is a member function that is declared in the base class using the keyword virtual and re-defined (or overridden) by a derived class. 

#include <iostream>

using namespace std;

class Base {
    public:
        virtual void display() {
            cout << "Called virtual base class function" << "\n\n"; 
        }

        void print() {
            cout << "Called non-virtual base class function" << "\n\n";
        }
};

class Derived : public Base {
    public:
        void display() {
            cout << "Called virtual derived class function" << "\n\n";
        }

        void print() {
            cout << "Called non-virtual derived class function" << "\n\n";
        }
};

int main() {
    Base* basePtr; // pointer to base class
    Derived d; // derived class object
    basePtr = &d; // basePtr points to the address of d

    // virtual function, binded at runtime (Runtime polymorphism)
    basePtr->Base::display(); // Called virtual base class function
    basePtr->display(); // Called virtual derived class function

    // Non-virtual function, binded at compile time
    basePtr->print(); // Called non-virtual base class function
    basePtr->Base::print(); // Called non-virtual base class function
}