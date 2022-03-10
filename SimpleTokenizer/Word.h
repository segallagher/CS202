#pragma once
#include <string>
using std::string;
#include <sstream>
using std::ostream;

class Word
{
public:
	Word(const string& word, const int& line, const int& column) :_word(word),_line(line),_column(column) {};
	friend std::ostream& operator<<(std::ostream& out, const Word& object) { out << "Line " << object._line  << ", Column" << object._column << ": \"" << object._word << "\""; return out; }
	int returnLine() { return _line; }
	string returnWord() { return _word; }
private:
	int _line;
	int _column;
	string _word;
};

