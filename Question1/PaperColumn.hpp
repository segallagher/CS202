#pragma once
#include <vector>
#include <string>

class PaperColumn
{
public:
	PaperColumn() {};
	PaperColumn(std::vector<std::string>& lines) { _lines = lines; }
	std::string returnLine(int& i) { return _lines.at(i); }
private:
	std::vector<std::string> _lines;
};

