#include <iostream>
#include "Rational.hpp"

int main()
{
    Rational a(6);
    Rational b(.776);
    a += 5;
    //a + b;
    //a + 5;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
}
