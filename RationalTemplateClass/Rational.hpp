#ifndef RATIONAL_HPP
#define RATIONAL_HPP
#include <iostream>
#include <numeric>

// 3/2, 5/1, 10/2, 1008882/23428, 1/2*1/3==1/6
// class invariant:
// _denominator is always > 0
template<class T>
class Rational {

private:
	T _numerator;
	T _denominator;
	void reduce();  // only Rational member fcns can call this

public:

	// Rational() { _numerator=0; _denominator=1; }
	Rational(T, T = 1);


    //last slide of last slides to declare friend in templated class
    template<typename U>
	friend std::ostream& operator<<(std::ostream&, const Rational<U>&);
	Rational& operator+=(const Rational<T>&);
    //template<typename U2>
	//friend Rational operator+(const Rational<U2>&, const Rational<U2>&);


#if 0
	friend Rational operator-(const Rational& lhs);
	friend bool operator==(const Rational& lhs, const Rational& rhs);
	friend bool operator<(const Rational& lhs, const Rational& rhs);

public:
	Rational& operator-=(const Rational& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);
	Rational& operator++();        //prefix ++
	Rational operator++(int); //postfix ++
	Rational& operator--();        //prefix --
	Rational operator--(int); //postfix --
private:

#endif
};

#if 0
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(Rational lhs, const Rational& rhs);
Rational operator/(Rational lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);
#endif

template<class T>
Rational<T>::Rational(T num, T den) : _numerator(num), _denominator(den) {
    reduce();
}

template<class T>
void Rational<T>::reduce() {
    int multiplier = 1;
    while (std::fmod(_numerator, 1.0) != 0 || std::fmod(_denominator, 1.0) != 0) {
        multiplier *= 10;
        _numerator *= 10;
        _denominator *= 10;
    }
    auto gcd = std::gcd((int)_numerator, (int)_denominator);
    _numerator /= (gcd * multiplier);
    _denominator /= (gcd * multiplier);
    if (_denominator < 0) {
        _numerator *= -1;
        _denominator *= -1;
    }
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Rational<T>& rhs) {
    os << rhs._numerator;
    if (rhs._denominator != 1)
        os << "/" << rhs._denominator;
    return os;
}

template<class T>
Rational<T>& Rational<T>::operator+=(const Rational<T>& rhs) {
    // a/b + c/d = (ad+bc)/ad
    _numerator = _numerator * rhs._denominator + rhs._numerator * _denominator;
    _denominator *= rhs._denominator;
    reduce();
    return *this;
}

template<class T>
Rational<T> operator+(const Rational<T>& lhs, const Rational<T>& rhs) {
    auto temp{ lhs };
    temp += rhs;
    return temp;
}




#endif