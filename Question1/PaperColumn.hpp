#pragma once
#include <vector>
#include <sstream>

class PaperColumn
{
public:
	PaperColumn() {};
	PaperColumn(std::vector<std::ostringstream>& lines) { _lines = lines; }
	//std::ostringstream& returnLine(int& i) { return _lines.at(i); }
private:
	std::vector<std::ostringstream> _lines;
};

