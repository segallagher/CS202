#pragma once
#include <vector>
#include <sstream>

class PaperColumn
{
public:
	PaperColumn() {};
	PaperColumn(std::vector<std::ostringstream>& lines) { _lines = lines; };

private:
	std::vector<std::ostringstream> _lines;
};

