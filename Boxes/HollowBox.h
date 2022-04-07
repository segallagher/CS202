#pragma once
#include "Box.h"
#include "FilledBox.h"
class HollowBox :
    public Box
{
public:
	HollowBox() : Box() {}
	HollowBox(const int& w) : Box(w) {}
	HollowBox(const int& w, const int& h) : Box(w,h) {}
    ~HollowBox(){}
    void draw() const;
};

