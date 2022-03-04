#define CATCH_CONFIG_MAIN
//#include "catch_amalgamated.hpp"  //BAD breaks code
#include "catch.hpp"
#include <iostream>
#include "Vector3f.h"

#if 0
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

#if 1
TEST_CASE("Vectors testing", "[Vector3f]") {
	REQUIRE(Vector3f() == Vector3f (0, 0, 0));
	REQUIRE(Vector3f() != Vector3f(5, 0, 0));
	REQUIRE(Vector3f(1,1,1).add(Vector3f(1,1,1)) == Vector3f(2,2,2));
	REQUIRE(Vector3f(1, 1, 1).sub(Vector3f(1, 1, 1)) == Vector3f());
	REQUIRE(Vector3f(1, 1, 1).scale(2) == Vector3f(2, 2, 2));
	REQUIRE(Vector3f(1, 1, 1).negate() == Vector3f(-1, -1, -1));
	REQUIRE(Vector3f(5,5,5).dot(Vector3f(8,5,7)) == 100);
	REQUIRE(Vector3f(5, 5, 5).cross(Vector3f(8, 5, 7)) == Vector3f(10,5,-15));
	REQUIRE(Vector3f(5, 0, 0).length() == 5);
	REQUIRE(Vector3f(6, 0, 0).unit() == Vector3f(1,0,0));
}
#endif