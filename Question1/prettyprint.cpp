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

void prettyPrint(vector<string> & paragraphs,const int & spacing) {
	char delim = ' ';
	ostringstream output;
	for (int i = 0; i < paragraphs.size(); i++) {
		ostringstream os;
		vector<string> tokens = Tokenize(paragraphs[i], delim);

		for (int k = 0; k < tokens.size(); k++) {
			
			if (os.str().size() + tokens.at(k).size() <= spacing && tokens.at(k) != tokens.at(tokens.size()-1)) {
				os << tokens.at(k) << " ";
			}
			else if (tokens.at(k) == tokens.at(tokens.size() - 1)) {
				os << tokens.at(k) << " ";
				os << "\n";
				output << os.str();
				os.str("");
			}
			else {
				os << "\n";
				output << os.str();
				os.str("");
				os << tokens.at(k) << " ";
			}

		}
		output << "\n";
	}
	std::cout << output.str() << std::endl;
	output.str() = "";
}

int main()
{
	ifstream file("pg67698.txt");
	string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	string s = removeDoubleNewline(str);
	istringstream stream(s);
	vector<string> paragraphs = separateParagraphs(stream);
	
	prettyPrint(paragraphs, 50);
}
