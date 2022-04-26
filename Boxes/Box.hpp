#pragma once

#ifndef BOX_HPP
#define BOX_HPP


#include <iostream>
#include <string>
using std::string;

class Box
{
public:
	Box() : _width(1), _height(1) {}
	Box(const int& w) : _width(w), _height(w) {}
	Box(const int& w, const int& h) : _width(w), _height(h) {}
	virtual string type() const = 0;
	virtual std::ostream& print(std::ostream&) const = 0;
	~Box() {}
	// cannot change "const Box& object" to "const Box* object" as BoxTest.cpp gives "const Box& object"
	friend std::ostream& operator<<(std::ostream& out, const Box& object) {
		auto sPtr = std::make_shared<Box>();
		return sPtr->print(out);}//return object->print(out);}

	int getWidth() const { return _width; }
	int getHeight() const { return _height; }

	void setWidth(const int& w) { _width = w; }
	void setHeight(const int& h) { _height = h; }
private:
	int _width;
	int _height;
};



#endif // !1