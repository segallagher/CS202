#pragma once
#include <iostream>
class Box
{
public:
	Box() : _width(2), _height(2) {}
	Box(const int& w) : _width(w), _height(w) {}
	Box(const int& w, const int& h) : _width(w), _height(h) {}
	virtual void draw() const = 0;

	int get_width() const { return _width; }
	int get_height() const { return _height; }

	void set_width(const int& w) { _width = w; }
	void set_height(const int& h) { _height = h; }
private:
	int _width;
	int _height;
};

