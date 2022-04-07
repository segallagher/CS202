#pragma once
#include "Box.h"
class FilledBox : public Box
{
public:
	FilledBox() { set_width(2); set_height(2); }
	FilledBox(const int& w) { set_width(w); set_height(w); }
	FilledBox(const int& w, const int& h) { set_width(w); set_height(h); }
	~FilledBox(){}
	void draw() const;
};

