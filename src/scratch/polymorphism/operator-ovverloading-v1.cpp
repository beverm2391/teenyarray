#include <iostream>


// compile time polymorphism
// operator overloading
using namespace std;
class Complex {
    private:
    int real, imag;

    public:
    Complex(int r = 0, int i = 0) : real{r}, imag{i} {}

    Complex operator + (Complex const &obj) {
        Complex res; // create a new object
        res.real = real + obj.real; // add the real parts
        res.imag = imag + obj.imag; // add the imaginary parts
        return res;
    };
    void print() { cout << real << " + i" << imag << endl; }
};

int main() {
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // An example call to "operator+"
    c3.print();
    return 0;
}