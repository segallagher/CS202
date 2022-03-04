#include "complex.h"

Complex& Complex::operator+=(const Complex & rhs) {
	_real += rhs._real;
	_imaginary += rhs._imaginary;
	return *this;
}

