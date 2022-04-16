#pragma once
#ifndef WRAPPER_HPP
#define WRAPPER_HPP


template<typename T>
class Wrapper
{
public:
	Wrapper(const T& data) : _data(data) {}
	~Wrapper(){}

	template<typename T>
	friend std::ostream& operator<< (std::ostream& out, const Wrapper<T>& object) { out << object._data; return out; };

private:
	T _data;
};

#endif // !1