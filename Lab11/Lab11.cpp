#include <iostream>

#include "Hat.h"
#include "Shirt.h"

void createHat(const int & num) {
    Hat h(num);
}

void createShirt(const int& num,const int& a) {
    Shirt(num, a);
}

int main()
{
    {Hat(); }
    std::cout << "--------------------------" << std::endl;
    createHat(7);
    std::cout << "--------------------------" << std::endl;
    {Shirt(); }
    std::cout << "--------------------------" << std::endl;
    createShirt(5, 3);
}
