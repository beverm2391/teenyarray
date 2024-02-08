#include <iostream>

using namespace std;
class Example {
    public:
    // functoni with one int parameter
        void func(int x) {
            cout  << "value of x is: " << x << endl;
        }

        // function with same name but one double parameter
        void func(double x) {
            cout << "value of x is: " << x << endl;
        }

        // function with same name but two int parameters
        void func(int x, int y) {
            cout << "value of x and y is: " << x << ", " << y << endl;
        }
};

int main() {
    Example obj; // create object of class

    // the function called depends on the parameters passed
    obj.func(7);
    obj.func(9.132);
    obj.func(85, 64);
    return 0;
}