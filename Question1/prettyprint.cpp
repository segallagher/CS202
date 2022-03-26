#include <iostream>
#include <vector>
using std::vector;
#include <string>;
using std::string;
#include <fstream>;
using std::ifstream;
#include <sstream>
using std::istringstream;
using std::ostringstream;

#include "Tokenizer.hpp"

vector<string> separateParagraphs(istringstream & file) {
	vector<string> paragraphs;
	string intermediary;
	while (std::getline(file,intermediary,'\n')) {
		paragraphs.push_back(intermediary);
	}
	return paragraphs;
}

string removeDoubleNewline(string & file) {
	string output;
	for (int i = 0; i < file.size(); i++) {
		if (file.at(i) == '\n' && (i + 1 == file.size() || file.at(i + 1) != '\n')) {
			output.push_back(' ');
		}
		else {
			output.push_back(file.at(i));
		}
	}
	return output;
}

void prettyPrint(vector<string> & paragraphs,int & spacing) {
	for (int i = 0; i < paragraphs.size(); i++) {
		ostringstream os;
		bool printing = true;
		while (printing) {

		}
	}
}

int main()
{
	ifstream file("pg67698.txt");
	string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	string s = removeDoubleNewline(str);
	istringstream stream(s);
	vector<string> paragraphs = separateParagraphs(stream);

	vector<string> out = Tokenize(paragraphs[1], ' ');
	for (auto n : out) {
		std::cout << n << std::endl;
	}
}
