#include <iostream>
#include <string>

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

void main(int argc,char *argv[]) {

	if (argc < 1) {
		std::cout << "Arguments needed" << std::endl;
	}
	else if (std::string(argv[1]) == "--ftoc") {
		std::cout << cpp_ftoc(argv[2]) << std::endl;
	}
	else if (std::string(argv[1]) == "--ctof") {
		std::cout << c_ctof(argv[2]) << std::endl;
	}
	else {
		std::cout << "Unknown error" << std::endl;
	}
}