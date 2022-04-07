#pragma once
#include "Box.h"
class FilledBox : public Box
{
public:
	FilledBox() : Box() {}
	FilledBox(const int& w) : Box(w) {}
	FilledBox(const int& w, const int& h) : Box(w, h) {}
	~FilledBox(){}
	void draw() const;
};

