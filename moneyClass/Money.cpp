#include "Money.h"

Money& Money::operator+=(const Money& rhs) {
	_cents += rhs._cents;
	return *this;
}

Money& Money::operator-=(const Money& rhs) {
	_cents -= rhs._cents;
	return *this;
}

bool Money::operator==(const Money& rhs) {
	return _cents == rhs._cents;
}

bool Money::operator!=(const Money& rhs) {
	return !(_cents == rhs._cents);
}

bool Money::operator<(const Money& rhs) {
	return _cents < rhs._cents;
}

bool Money::operator<=(const Money& rhs) {
	return _cents < rhs._cents || _cents == rhs._cents;
}

bool Money::operator>(const Money& rhs) {
	return _cents > rhs._cents;
}

bool Money::operator>=(const Money& rhs) {
	return _cents > rhs._cents || _cents == rhs._cents;
}

Money& Money::operator*=(const double& num) {
	_cents *= num;
	return *this;
}

Money& Money::operator/=(const double& num) {
	_cents /= num;
	return *this;
}