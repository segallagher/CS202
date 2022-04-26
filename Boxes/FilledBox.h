#pragma once
#include "Box.hpp"

class FilledBox : public Box
{
public:
	FilledBox() : Box() {}
	FilledBox(const int& w) : Box(w) {}
	FilledBox(const int& w, const int& h) : Box(w, h) {}
	~FilledBox(){}

	std::ostream& print(std::ostream&) const override;
	string type() const override { return "Filled"; }

};

