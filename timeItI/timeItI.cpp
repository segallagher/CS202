#include <iostream>
#include <vector>
#include "Stopwatch.h"
#include <random>
#include <algorithm>

int main()
{
	std::vector<int> dummy(259999999);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1,dummy.size());

	for (int i = 0; i < dummy.size(); i++) {
		dummy.at(i) = i;
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

	std::cout << "Search Time: \t\t" << search.readMilliseconds().count() << std::endl;
	std::cout << "Binary Search Time: \t" << binary.readMilliseconds().count() << std::endl;
}
