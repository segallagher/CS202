#pragma once
#include <iostream>
class Hat
{
public:
	Hat() { std::cout << "Default Hat created" << std::endl; }
	Hat(const int& num): _num(num) { std::cout << "Hat Created, num is " << _num << std::endl; }
	~Hat() { std::cout << "Hat Deleted, num is " << _num << std::endl; }
	int _num;
};

