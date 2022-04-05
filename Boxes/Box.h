#pragma once
#include <iostream>
class Box
{
public:
	Box() : _width(2), _height(2) {}
	Box(const int & w) : _width(w), _height(w) {}
	Box(const int& w, const int& h) : _width(w), _height(h) {}
	~Box(){}
	void draw() const;
protected:
	int _width;
	int _height;
};

