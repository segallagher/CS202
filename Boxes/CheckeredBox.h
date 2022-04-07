#pragma once
#include "Box.h"
class CheckeredBox :
    public Box
{
public:
	CheckeredBox() { set_width(2); set_height(2); }
	CheckeredBox(const int& w) { set_width(w); set_height(w); }
	CheckeredBox(const int& w, const int& h) { set_width(w); set_height(h); }
	~CheckeredBox() {}
	void draw() const;
};

