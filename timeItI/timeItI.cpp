#include <iostream>
#include <vector>
#include "Stopwatch.h"
#include <random>
#include <algorithm>
#include <iomanip>

std::vector<int> runTests(int & size) {
	std::cout << "--Size-" << size << "--" << std::endl;
	std::vector<int> results;
	for (int i = 0; i < 5; i++) {
		std::cout << "Test " << i << std::endl;
		std::vector<int> dummy;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(1, size);

		for (int i = 0; i < size; i++) {
			dummy.push_back(i);
		}

		int target = dist(gen);
		//std::cout << "Target: " << target << std::endl;
		//std::cout << "Search Algorithm" << std::endl;

		Stopwatch search;
		search.start();

		for (auto n : dummy) {
			if (n == target) {
				std::cout << "FOUND " << n << std::endl;
				break;
			}
		}

		search.stop();
		//std::cout << "Search Completed" << std::endl;
		//std::cout << "Binary_Search Algorithm" << std::endl;

		//std::vector<int>::iterator it;
		//it = std::find(dummy.begin(), dummy.end(), target);

		Stopwatch binary;
		binary.start();
		int a = std::binary_search(dummy.begin(), dummy.end(), target);
		std::cout << "Target Found" << a << std::endl;
		binary.stop();

		//std::cout << "Binary_Search Completed" << std::endl;

		results.push_back(search.readMicroseconds().count());
		results.push_back(binary.readMicroseconds().count());
	}
	std::vector<int> averageResults;
	int avgSearch = 0;
	for (int i = 0; i < 5; i++) {
		avgSearch += results.at(2 * i);
	}
	avgSearch = avgSearch / 5;
	int avgBinary = 0;
	for (int i = 0; i < 5; i++) {
		avgBinary += results.at(2 * i+1);
	}
	avgBinary = avgBinary / 5;
	averageResults.push_back(avgSearch);
	averageResults.push_back(avgBinary);
	std::cout << avgSearch << " " << avgBinary << std::endl;
	return averageResults;
}

int main()
{
	std::vector<int> allAverageResults;
	//1000000000
	for (int size = 10; size <= 1000000000; size = size * 10) {
		std::vector<int> results = runTests(size);
		allAverageResults.push_back(results[0]);
		allAverageResults.push_back(results[1]);
	}
	std::cout << std::setw(15) << "\t\tLinear " << "\tBinary (Microseconds)" << std::endl;
	int size = 1;
	for (int i = 0; i < 9;i++) {
		size = size * 10;
		std::cout << std::setw(10) << size << std::setw(10) << allAverageResults.at(2 * i) << std::setw(10) << allAverageResults.at(2 * i + 1) << std::endl;
	}
	
}
