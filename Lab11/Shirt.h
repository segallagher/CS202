#pragma once
#include "Hat.h"

class Shirt :
    public Hat
{
public:
    Shirt() { std::cout << "Default Shirt created" << std::endl; }
    Shirt(const int& num, const int& a) : Hat(num), _a(a) {std::cout << "Shirt Created, a is " << _a << std::endl; }
    ~Shirt() { std::cout << "Shirt Deleted, a is " << _a << std::endl; }
    int _a;
};

