#pragma once
#include "Box.hpp"
#include <string>
class CheckeredBox :
    public Box
{
public:
	CheckeredBox() : Box() {}
	CheckeredBox(const int& w) : Box(w) {}
	CheckeredBox(const int& w, const int& h) : Box(w, h) {}
	~CheckeredBox() {}
	std::ostream& print(std::ostream&) const override;
	string type() const override { return "Checkered"; }
};

