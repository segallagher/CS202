#pragma once
#ifndef VECTOR3F_HPP

#include <iostream>
using std::ostream;

class Vector3f
{
public:
	Vector3f();
	Vector3f(float x, float y, float z);
	Vector3f(const Vector3f & b);
	~Vector3f() {}
	bool operator ==(const Vector3f& b) const;
	bool operator !=(const Vector3f& b) const;

	friend ostream& operator<<(ostream& out, Vector3f a) { out << "[" << a.x << "," << a.y << "," << a.z << "]"; return out; }
	
	Vector3f add(const Vector3f& b);
	Vector3f sub(const Vector3f& b);
	Vector3f scale(const float& c);
	Vector3f negate();
	float dot(const Vector3f& b);
	Vector3f cross(const Vector3f& b);
	float length();
	Vector3f unit();
private:
	float x;
	float y;
	float z;
};


#endif // !VECTOR3F_HPP