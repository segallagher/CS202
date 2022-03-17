#include "Money.hpp"

Money& Money::operator+=(const Money& rhs) {
	_cents += rhs._cents;
	return *this;
}

Money& Money::operator-=(const Money& rhs) {
	_cents -= rhs._cents;
	return *this;
}

Money& Money::operator*=(const float& num) {
	_cents *= num;
	return *this;
}

Money& Money::operator/=(const float& num) {
	_cents /= num;
	return *this;
}