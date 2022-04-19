#include <iostream>
#include "myreadwrite.hpp"

int main()
{
	std::ofstream ofile("test.txt", std::ios::out, std::ios::binary);
	myWrite(ofile, 65);
	myWrite(ofile, 42);
	myWrite(ofile, 1);
	myWrite(ofile, 77);
	ofile.close();
	std::ifstream ifile("test.txt", std::ios::in, std::ios::binary);
	int a;
	myRead(ifile, a);
	while (!ifile.eof()) {
		std::cout << a << std::endl;
		myRead(ifile, a);
	}
}
