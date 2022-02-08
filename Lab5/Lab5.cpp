#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using std::vector;
using std::string;
using std::istringstream;

int vecFindSum(vector<int>& vec) {
	int sum = 0;
	for (auto n : vec) {
		sum += n;
	}
	return sum;
}

int main()
{
	string fileName = "data.dat";
	std::ifstream file;
	file.open(fileName, std::ios::out | std::ios::binary);
	if (!file) {
		std::cout << "Error opening file " << fileName << std::endl;
	}
	vector<int> numbers;
	int jum;
	while (file.read(reinterpret_cast<char*>(&jum), sizeof(int))) {
		numbers.push_back(jum);
	}

	int sum = vecFindSum(numbers);

	std::cout << "Count:\t" << numbers.size() << std::endl;
	std::cout << "Sum:\t" << sum << std::endl;
	std::cout << "Average:" << double(sum) / numbers.size() << std::endl;
}