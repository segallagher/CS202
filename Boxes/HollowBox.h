#pragma once
#include "FilledBox.h"
class HollowBox :
    public FilledBox
{
public:
    HollowBox(): FilledBox(){}
    HollowBox(const int& w) : FilledBox(w) {}
    HollowBox(const int& w, const int& h) : FilledBox(w,h) {}
    ~HollowBox(){}
    void draw() const;
};

