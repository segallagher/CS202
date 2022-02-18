#include "Vector3f.h"

Vector3f::Vector3f() {
	x = 0;
	y = 0;
	z = 0;
}

Vector3f::Vector3f(float a, float b, float c) {
	x = a;
	y = b;
	z = c;
}

Vector3f::Vector3f(const Vector3f& b) {
	x = b.x;
	y = b.y;
	z = b.z;
}
bool Vector3f::operator==(const Vector3f& b) const { return (x == b.x) && (y == b.y) && (z == b.z); };
bool Vector3f::operator!=(const Vector3f& b) const { return (x != b.x) || (y != b.y) || (z != b.z); };

Vector3f Vector3f::add(const Vector3f& b) { return Vector3f(x + b.x, y + b.y, z + b.z); };
Vector3f Vector3f::sub(const Vector3f& b) { return Vector3f(x - b.x, y - b.y, z - b.z); };
Vector3f Vector3f::scale(const float& c) { return Vector3f(x * c, y * c, z * c); };
Vector3f Vector3f::negate() { return Vector3f(-x,-y,-z); };
float Vector3f::dot(const Vector3f& b) { return x * b.x + y * b.y + z * b.z; };
Vector3f Vector3f::cross(const Vector3f& b) { return Vector3f(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x); };
float Vector3f::length() { return std::sqrt(x * x + y * y + z * z); };
Vector3f Vector3f::unit() { float scale = 1 / std::sqrt(x * x + y * y + z * z); return Vector3f(x * scale, y * scale, z * scale); };
