#include "caveJunction.h"

CaveJunction::CaveJunction(const string& d1, const string& d2, const string& d3) {
	_connections = std::vector<string>{ d1, d2, d3 };
}

string CaveJunction::printOptions(const map<string, CaveJunction>& caveSystem, const string& currentLocation, const string& previousLocation) {
	std::cout << "Current Location: " << currentLocation << std::endl;
	std::vector<string> cave = caveSystem.at(currentLocation)._connections;
	string left, right, back;
	for (auto i = 0; i < 3; i++) {
		if (previousLocation == cave.at(i)) {
			switch (i)
			{
			case 0:
				back = cave.at(i); left = cave.at(i + 1); right = cave.at(i + 2); break;
			case 1:
				back = cave.at(i); left = cave.at(i + 1); right = cave.at(i - 1); break;
			case 2:
				back = cave.at(i); left = cave.at(i - 2); right = cave.at(i - 1); break;
			default:
				break;
			}
		}

	}
	if (left != ""){
		std::cout << "- Go left to " << left << std::endl;
	}
	if (right != "") {
		std::cout << "- Go Right to " << right << std::endl;
	}
	std::cout << "- Go Back to " << back << std::endl;
	std::cout << "Enter Here: ";
	string line;
	string lowerLine;
	std::getline(std::cin, line);
	for (auto n : line) {
		lowerLine.push_back(char(std::tolower(n)));
	}
	if (lowerLine == "left" || lowerLine == left) {
		return left;
	}
	else if (lowerLine == "right" || lowerLine == right) {
		return right;
	}
	else if (lowerLine == "back" || lowerLine == back) {
		return back;
	}
	else {
		std::cout << "Please enter a valid option" << std::endl;
		return "";
	}
}