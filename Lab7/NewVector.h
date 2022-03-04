#pragma once
#include <Vector>
using std::vector;
#include <sstream>
using std::ostream;

class NewVector
{
public:
	NewVector();
	NewVector(const vector<int>& vec);
	void append(const int& num);
	~NewVector(){}
	friend ostream& operator<<(ostream& out,const NewVector& a) { out << "["; for (auto n : a._vec) { out << n << ","; }out << "]"; return out; };
private:
	vector<int> _vec;
};

