#include "Rational.hpp"
#if 0
#include <numeric>


template<class T>
Rational<T>::Rational(T num, T den) : _numerator(num), _denominator(den) {
    reduce();
}

template<class T>
void Rational<T>::reduce() {
    auto gcd = std::gcd(_numerator, _denominator);
    _numerator /= gcd;
    _denominator /= gcd;
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

#if 0

Rational operator-(const Rational& lhs) {
    return { -lhs._numerator, lhs._denominator };
}

Rational& Rational::operator-=(const Rational& rhs) { //Canonical
    *this = *this - rhs; //uses Rational::operator- to define operator-=
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
    _numerator *= rhs._numerator;
    _denominator *= rhs._denominator;
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
    return *this *= {rhs._denominator, rhs._numerator};
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    return lhs + -rhs;
}

// pass lhs by value because we were going to copy it anyway
Rational operator*(Rational lhs, const Rational& rhs) { //Canonical
    return lhs *= rhs;
}

// pass lhs by value because we were going to copy it anyway
Rational operator/(Rational lhs, const Rational& rhs) { //Canonical
    return lhs /= rhs;
}

Rational& Rational::operator++() {//prefix ++
    return *this += 1;
}

Rational Rational::operator++(int) {//postfix ++
    auto copy{ *this };
    ++(*this);
    return copy;
}

Rational& Rational::operator--() {//prefix --
    return *this -= 1;
}

Rational Rational::operator--(int) {//postfix --
    auto copy{ *this };
    --(*this);
    return copy;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs._numerator == rhs._numerator && lhs._denominator == rhs._denominator;
}

bool operator!=(const Rational& lhs, const Rational& rhs) {//canonical
    return !(rhs == lhs);
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    return lhs._numerator * rhs._denominator < rhs._numerator* lhs._denominator;
}

bool operator>(const Rational& lhs, const Rational& rhs) {//canonical
    return rhs < lhs;
}

bool operator<=(const Rational& lhs, const Rational& rhs) {//canonical
    return !(rhs > lhs);
}

bool operator>=(const Rational& lhs, const Rational& rhs) {//canonical
    return !(rhs < lhs);
}
#endif