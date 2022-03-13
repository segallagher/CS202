#pragma once
#include <string>
using std::string;
#include <sstream>
using std::ostream;
#include <iomanip>
using std::setprecision;

class Money
{
public:
	Money(){ _cents = 0; }
	Money(const double &zimflop) { _cents = zimflop * 100; }
	Money(const int& dollars, const int&cents) { _cents = dollars * 100 + cents; }
	~Money(){}
	friend std::ostream& operator<<(std::ostream& out, const Money& object) { if (object._cents < 0) { out << "-"; } out << "$"; out << std::fixed << std::setprecision(2) << std::abs(object._cents / 100.0); return out; }
	friend Money operator+(const Money& lhs, const Money& rhs) { return Money(lhs) += rhs; };
	Money& operator+=(const Money&);
	friend Money operator-(const Money& lhs, const Money& rhs) { return Money(lhs) += rhs; };
	Money& operator-=(const Money&);
	bool operator==(const Money&);
	bool operator!=(const Money&);
	bool operator<(const Money&);
	bool operator<=(const Money&);
	bool operator>(const Money&);
	bool operator>=(const Money&);
	friend Money& operator*(const Money& lhs, const Money& rhs) { return Money(lhs) * rhs; };
	Money& operator*=(const double&);
	friend Money& operator/(const Money& lhs, const Money& rhs) { return Money(lhs) / rhs; };
	Money& operator/=(const double&);
private:
	float _cents;
};

