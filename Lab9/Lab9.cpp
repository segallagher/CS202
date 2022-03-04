#include <iostream>
#include "complex.h"

int main()
{
	Complex a(5.1);
	Complex b(3, -2);
	Complex d = a + b;
	//a += b;
	std::cout << a << " | " << b << std::endl;
	std::cout << d << std::endl;
	std::cout << a << " | " << b << std::endl;

	Complex e = d + 1;
	Complex f = 1.12 + d;
	std::cout << e << std::endl;
	std::cout << f << std::endl;
	std::cout << b + 6.0 << std::endl;
	//std::cout << d + 1 << std::endl;
}