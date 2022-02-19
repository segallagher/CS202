#pragma once
#include <list>
//#include <algorithm>
#include <iostream>
using std::ostream;

struct Something
{
    Something();
    Something(std::list<int>& list);
    void queue(const int & num);
    void stack(const int& num);
    void insertion(const int& num);
    bool search(const int& num);
    void sort();
    ~Something() {}

    friend ostream& operator<<(ostream& out, Something& a) {
        out << "["; std::list<int>::iterator it = a._vList.begin(); for (int i = 0; i < a._vList.size(); i++) { out << *it; if (i != a._vList.size()-1) { out << ","; } it++; }; out << "]"; return out;
    };
private:
    std::list<int> _vList;
};

