#pragma once
#include <sstream>
using std::ostream;
class Complex
{
public:
	Complex(const double real, const double imaginary = 0) : _real(real), _imaginary(imaginary) {}
	~Complex(){}
	friend std::ostream& operator<<(std::ostream& out,const Complex& object) { out << object._real; if (object._imaginary >= 0) { out << "+"; } out << object._imaginary << "i"; return out; }
	friend Complex operator+(const Complex& lhs, const Complex& rhs) {return Complex(lhs) += rhs;};
	Complex& operator+=(const Complex&);

private:

	double _real;
	double _imaginary;
};

