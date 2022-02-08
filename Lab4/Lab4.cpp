#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using std::ifstream;
using std::string;
using std::istringstream;

void printFile(const string & fileName) {
	ifstream file (fileName);
	if (!file) {
		std::cout << "Error opening file " << fileName << std::endl;
	}
	string line;
	while (std::getline(file,line)) {
		std::cout << line << std::endl;
	}
}

void appendText(int& number, string& input, string & fileName) {
	const int num = number; const string words = input;
	std::ofstream file;
	if (!file) {
		std::cout << "Error opening file " << fileName << std::endl;
	}
	file.open(fileName,std::ios_base::app);
	for (int i = 0; i < num; i++) {
		file << std::endl << words;
	}
}

std::pair<int, string> processInput(const string & input) {
	int number; string words;
	istringstream sstr(input);
	sstr >> number;
	words = sstr.str();
	words.erase(words.begin(), words.begin() + std::to_string(number).size() + 1);
	return std::make_pair(number, words);
}

int main()
{
	string fileName = "text.txt";
	printFile(fileName);

	string input;
	std::cout << "Enter a number followed by a string: " << std::endl;
	std::getline(std::cin, input);
	std::pair<int,string> data = processInput(input);

	appendText(data.first, data.second,fileName);
}