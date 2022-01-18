#include <iostream>


double cpp_ftoc(const char* str) {
	char* temp;
	double fahrenheit = std::strtod(str, &temp);
	return (fahrenheit - 32) * 5 / 9;
}

double c_ctof(const char* str) {
	char* temp;
	double celsius = std::strtod(str, &temp);
	return celsius * 9 / 5 + 32;
}

void main(int argc, const char** argv) {
	std::cout << cpp_ftoc("35") << std::endl;
	std::cout << c_ctof("35") << std::endl;
}