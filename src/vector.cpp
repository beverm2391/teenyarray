#include <iostream>
#include <vector>
#include <cmath>

class Tvec
{
public:
    std::vector<double> elements;

    Tvec(std::initializer_list<double> init) : elements(init) {} // init list constructor

    Tvec operator+(const Tvec &rhs) const
    {
        Tvec result(*this);
        for (int i = 0; i < elements.size(); i++)
        {
            result.elements[i] += rhs.elements[i];
        }
        return result;
    };

    Tvec operator-(const Tvec &rhs) const
    {
        Tvec result(*this);
        for (int i = 0; i < elements.size(); i++)
        {
            result.elements[i] -= rhs.elements[i];
        }
        return result;
    };
};

// main function
int main()
{
    // do some stuff
    Tvec v1 = {1, 2, 3};
    Tvec v2 = {4, 5, 6};
    Tvec v3 = v1 + v2;

    // print the results
    std::cout << "v3: ["; // the "<< " is the "insertion operator which "inserts" the string into the output stream "std::cout"
    for (auto &e : v3.elements) // auto is a placeholder for the type of the variable. "&" is a ref to the variable. . notation accesses the elements of the vector
    {
        std::cout << e << " ";
    };
    std::cout << "]" << std::endl;

    return 0;
}