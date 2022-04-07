#pragma once
#include <iostream>
#include "Box.h"
class FilledBox// : public Shape
{
public:
	FilledBox() : _width(2), _height(2) {}
	FilledBox(const int & w) : _width(w), _height(w) {}
	FilledBox(const int& w, const int& h) : _width(w), _height(h) {}
	~FilledBox(){}
	void draw() const;
protected:
	int _width;
	int _height;
};

