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
#include "PaperColumn.hpp"

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

void printString(string& str) {
	std::cout << str << std::endl;
}

string prettyPrint(vector<string> & paragraphs,const int & spacing) {
	char delim = ' ';
	ostringstream output;
	for (int i = 0; i < paragraphs.size(); i++) {	// iterate over all paragraphs
		ostringstream os;
		vector<string> tokens = Tokenize(paragraphs[i], delim);


		for (int k = 0; k < tokens.size(); k++) {	// iterate over all words in a paragraph
			
			if (os.str().size() + tokens.at(k).size() <= spacing && tokens.at(k) != tokens.at(tokens.size()-1)) {	//make sure not at end of paragraph and not going over spacing # of characters
				os << tokens.at(k) << " ";
			}
			else if (tokens.at(k) == tokens.at(tokens.size() - 1)) {	// if at end of paragraph
				if (os.str().size() + tokens.at(k).size() <= spacing) {
					os << tokens.at(k) << " ";
					os << "\n";
					output << os.str();
					os.str("");
				}
				else {
					os << "\n";
					os << tokens.at(k) << " ";
					output << os.str();
					os.str("");
				}
			}
			else {	// if at end of line, newline and add word to beginning of next line
				os << "\n";
				output << os.str();
				os.str("");
				os << tokens.at(k) << " ";
			}

		}
		output << "\n";
	}
	return output.str();
}

void twocolumn(vector<string>& paragraphs,const int & lines, const int& spacing, const int & margin) {
	vector<PaperColumn> paper;

}

int main(int argc, char* argv[])
{
	string filename = argv[2];

	ifstream file(filename);	//open file
	string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	string s = removeDoubleNewline(str);	// remove \n after every line in project gutenburg books that makes it human readable
	istringstream stream(s);
	vector<string> paragraphs = separateParagraphs(stream);	// separate book into paragraphs

	if (string(argv[1]) == "prettyprint") {
		int spacing = atoi(argv[3]);
		string s = prettyPrint(paragraphs, spacing);
		printString(s);
	}

}
