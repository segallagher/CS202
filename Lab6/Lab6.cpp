//#define CATCH_CONFIG_MAIN
//#include "catch_amalgamated.hpp"
#include <iostream>
#include "Vector3f.h"

#if 1
int main() {
	Vector3f a (0,0,0);
	Vector3f b;
	Vector3f c(5, 5, 5);
	std::cout << a << std::endl;
	if (a == b) {std::cout << "Equal" << std::endl; };
	if (a != c) { std::cout << "Not Equal" << std::endl; };
	Vector3f d(c);
	std::cout << c << " " << d << std::endl;
	Vector3f e(8, 5, 7);

	std::cout << a.add(c).add(c) << std::endl;
	std::cout << a.sub(c) << std::endl;
	std::cout << c.scale(5) << std::endl;
	std::cout << e.negate() << std::endl;
	std::cout << c.dot(e) << std::endl;
	std::cout << c.cross(e) << std::endl;
	std::cout << c.length() << std::endl;
	std::cout << c.unit() << std::endl;
}
#endif

#if 0
TEST_CASE("Vectors testing", "[Vector3f}") {
	Vector3f a;
	Vector3f b(0, 0, 0);
	REQUIRE(a == b);
}
#endif