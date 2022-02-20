#include "caveJunction.h"

CaveJunction::CaveJunction(const string& d1, const string& d2, const string& d3) {
	_connections = std::vector<string>{ d1, d2, d3 };
}

string CaveJunction::printOptions(const map<string, CaveJunction>& caveSystem, const string& currentLocation, const string& previousLocation){
	std::vector<string> cave = caveSystem.at(currentLocation)._connections;
	string left,right,back;
	for (auto i = 0; i < 3; i++) {
		if (previousLocation == cave.at(i)) {
			switch (i)
			{
			case 0:
				back = cave.at(i);left = cave.at(i + 1);right = cave.at(i + 2); break;
			case 1:
				back = cave.at(i); left = cave.at(i + 1); right = cave.at(i - 1); break;
			case 2:
				back = cave.at(i); left = cave.at(i - 2); right = cave.at(i - 1); break;
			default:
				break;
			}
		}
		
	}
	std::cout << "1) Go left to " << left << std::endl;
	std::cout << "2) Go Right to " << right << std::endl;
	std::cout << "3) Go Back to " << back << std::endl;
	std::cout << "Enter Here: ";
	string line;
	std::getline(std::cin, line);
	for (auto n : line) {
		tolower(n);
	}
	if (line == "1" || line == "left" || line == left) {
		return left;
	}
	else if (line == "2" || line == "right" || line == right) {
		return right;
	}
	else if (line == "3" || line == "back" || line == back) {
		return back;
	}
	else {
		std::cout << "Please enter a valid option" << std::endl;
		return "";
	}
}