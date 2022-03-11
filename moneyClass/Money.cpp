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