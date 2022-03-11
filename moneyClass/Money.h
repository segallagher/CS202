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
	Money(const int &zimflop) { _cents = zimflop; }
	~Money(){}
	friend std::ostream& operator<<(std::ostream& out, const Money& object) { out << "$" << object._cents / 100.0; if (object._cents == 0) { out << ".0"; } if (object._cents % 10 == 0) { out << "0"; }  return out; }
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
private:
	int _cents;
};

