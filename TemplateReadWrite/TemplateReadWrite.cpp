#include <iostream>
#include "myreadwrite.hpp"
#include <vector>

int main()
{
	// Create file with doubles
	std::vector<double> doubles{ 35,-62,60.9,1.0 };
	std::ofstream ofile("doubles.txt", std::ios::out, std::ios::binary);
	for (auto n : doubles) {
		myWrite(ofile, n);
	}
	ofile.close();

	// Read file with doubles
	std::ifstream ifile("doubles.txt", std::ios::in, std::ios::binary);
	double a;
	myRead(ifile, a);
	while (!ifile.eof()) {
		std::cout << a << std::endl;
		myRead(ifile, a);
	}

	std::cout << "--------------------------" << std::endl;

	// Create file with ints
	std::vector<int> ints{ 1,-7,8,94 };
	std::ofstream ofile2("ints.txt", std::ios::out, std::ios::binary);
	for (auto n : ints) {
		myWrite(ofile2, n);
	}
	ofile2.close();

	// Read file with ints
	std::ifstream ifile2("ints.txt", std::ios::in, std::ios::binary);
	int b;
	myRead(ifile2, b);
	while (!ifile2.eof()) {
		std::cout << b << std::endl;
		myRead(ifile2, b);
	}
}
