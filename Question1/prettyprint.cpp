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
#include <iomanip>
using std::setw;

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

void printColumns(vector<PaperColumn>& papers,const int &columns, const int& lines, const int& spacing, const int& margin) {
	// Very much not DRY
	char sheetDividerChar = '-';
	char pageDividerChar = ' ';

	ostringstream out;
	int printedPapers = 0;
	for (int i = 0; i < papers.size(); i+= columns) { //sheets
		if (papers.size() - i < columns) { break; }
		for (int k = 0; k < lines; k++) {//lines
			for (int q = 0; q < columns; q++) {//columns
				if (!(k < lines - 0)) {
					out << setw(spacing) << std::left << papers.at(printedPapers + q).returnLine(k);
				}
				else {
					out << setw(spacing) << std::left << papers.at(printedPapers + q).returnLine(k).substr(0, papers.at(printedPapers + q).returnLine(k).size() - 1);
				}
				if (q < columns-1) {
					for (int s = 0; s < margin; s++) {
						out << pageDividerChar;
					}
				}
			}
			out << '\n';
		}
		printedPapers += columns;
		for (int i = 0; i < columns * (spacing + margin) - margin;i++) {
			out << sheetDividerChar;
		}
		out << "\n";
	}
	// last pages, Very much not DRY, could be rewritten but this code has been going on far too long
	if (printedPapers < papers.size()) {
		int remaining = papers.size() - printedPapers;
			for (int k = 0; k < lines; k++) {//lines
				for (int q = 0; q < remaining; q++) {//columns
					if (!(k < lines - 0)) {
						out << setw(spacing) << std::left << papers.at(printedPapers + q).returnLine(k);
					}
					else {
						out << setw(spacing) << std::left << papers.at(printedPapers + q).returnLine(k).substr(0, papers.at(printedPapers + q).returnLine(k).size()-1);
					}
					if (q < columns - 1) {
						for (int s = 0; s < margin; s++) {
							out << pageDividerChar;
						}
					}
				}
				out << '\n';
			}
			printedPapers += columns;
			for (int i = 0; i < columns * (spacing + margin) - margin;i++) {
				out << sheetDividerChar;
			}
			out << "\n";
	}
	std::cout << out.str() << std::endl;
}

string generatePaper(vector<string>& bookLines, const int& lines, const int& spacing, const int& margin) {
	ostringstream out;
	for (int g = 0; g < lines; g++) {
		out << *bookLines.begin() << '\n';
		bookLines.erase(bookLines.begin());
	}

	return out.str();
}

void appendPaper(vector<PaperColumn>& papers, string& paper) {
	vector<string> ba = Tokenize(paper, '\n');
	PaperColumn a(ba);
	papers.push_back(a);
}

void twocolumn(vector<string>& paragraphs, const int& lines, const int& spacing, const int& margin) {
	vector<PaperColumn> papers;
	string bookString = prettyPrint(paragraphs, spacing);
	vector<string> bookLines = Tokenize(bookString,'\n');
	while (bookLines.size() % lines != 0) {
		bookLines.push_back("");
	}

	int columns = 5;
	int totalLines = 0;
	double tmp = bookLines.size() / (double)lines;
	int totalPages = (int) ceil((float) bookLines.size() / lines);
	
	for (int i = 0; i < totalPages; i++) {
		string a = generatePaper(bookLines, lines, spacing, margin);
		appendPaper(papers, a);
	}

	printColumns(papers, columns, lines, spacing, margin);

}

int main(int argc, char* argv[])
{
	//string filename = argv[2];
	string filename = "pg67698.txt";

	ifstream file(filename);	//open file
	string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	string s = removeDoubleNewline(str);	// remove \n after every line in project gutenburg books that makes it human readable
	istringstream stream(s);
	vector<string> paragraphs = separateParagraphs(stream);	// separate book into paragraphs
	/*
	if (string(argv[1]) == "prettyprint") {
		int spacing = atoi(argv[3]);
		string s = prettyPrint(paragraphs, spacing);
		printString(s);
	}
	else if (string(argv[1]) == "twocolumn") {
		int lines = atoi(argv[3]);
		int spacing = atoi(argv[4]);
		int margin = atoi(argv[5]);
		twocolumn(paragraphs, lines, spacing, margin);
	}
	*/

	int lines = 40;//40
	int spacing = 38;//38
	int margin = 4;//4
	twocolumn(paragraphs, lines, spacing, margin);
}
