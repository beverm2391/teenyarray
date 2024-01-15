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
    std::cout << "v3: [";
    for (auto i = v3.elements.begin(); i != v3.elements.end(); ++i)
    {
        std::cout << *i; // print the element
        if (std::next(i) != v3.elements.end()) // if this is not the last element
        {
            std::cout << " ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}