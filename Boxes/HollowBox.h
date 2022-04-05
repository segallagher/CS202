#pragma once
#include "Box.h"
class HollowBox :
    public Box
{
    HollowBox(): Box(){}
    HollowBox(const int& w) : Box(w) {}
    HollowBox(const int& w, const int& h) : Box(w,h) {}
    ~HollowBox(){}
    void draw() const;
};

