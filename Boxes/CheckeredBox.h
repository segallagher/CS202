#pragma once
#include "Box.h"
class CheckeredBox :
    public Box
{
public:
	CheckeredBox() : Box() {}
	CheckeredBox(const int& w) : Box(w) {}
	CheckeredBox(const int& w, const int& h) : Box(w, h) {}
	~CheckeredBox() {}
	void draw() const;
};

