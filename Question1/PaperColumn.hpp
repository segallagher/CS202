#pragma once
#include <vector>
#include <string>
#include <iostream>

class PaperColumn
{
public:
	PaperColumn() {};
	PaperColumn(std::vector<std::string>& lines) { _lines = lines; }
	void appendLine(const std::string& str) { _lines.push_back(str); }
	std::string returnLine(int& i) { return _lines.at(i); }
private:
	std::vector<std::string> _lines;
};

