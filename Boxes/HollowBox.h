#pragma once
#include "Box.hpp"
#include "FilledBox.h"
class HollowBox :
    public Box
{
public:
	HollowBox() : Box() {}
	HollowBox(const int& w) : Box(w) {}
	HollowBox(const int& w, const int& h) : Box(w,h) {}
    ~HollowBox(){}
	std::ostream& print(std::ostream&) const override;
	string type() const override { return "Hollow"; }
};

