#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "Money.h"

#if 0
int main()
{
	Money b(-1.547);
	Money a = Money(430);
	if (a == b) {
		std::cout << "Equal" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
	std::cout << b << std::endl;
}

#else

TEST_CASE("Money Testing", "[Money]") {
	REQUIRE(Money(1) == Money(1));
}
#endif