#include <iostream>
#include <vector>
#include "Stopwatch.h"
#include <random>
#include <algorithm>

int main()
{
	int size = 25999999;
	std::vector<int> dummy;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1,size);

	for (int i = 0; i < size; i++) {
		dummy.push_back(i);
	}

	int target = dist(gen);
	std::cout << "Target: " << target << std::endl;
	std::cout << "Search Algorithm" << std::endl;

	Stopwatch search;
	search.start();

	for (auto n : dummy) {
		if (n == target) {
			//std::cout << "FOUND " << n << std::endl;
			break;
		}
	}

	search.stop();
	std::cout << "Search Completed" << std::endl;
	std::cout << "Binary_Search Algorithm" << std::endl;

	Stopwatch binary;
	binary.start();
	std::binary_search(dummy.begin(), dummy.end(), target);
	binary.stop();

	std::cout << "Binary_Search Completed" << std::endl;

	std::cout << "Search Time: \t\t" << search.readNanoseconds().count() << std::endl;
	std::cout << "Binary Search Time: \t" << binary.readNanoseconds().count() << std::endl;
}
