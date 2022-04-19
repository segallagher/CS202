#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"

int fib(const int& n) {
	if (n == 1 || n == 0) {
		return n;
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
}

int fib_loop(const int& n) {
	int a = 0;
	int b = 1;
	for (int i = 0; i < n - 1; i++) {
		int tmp = b;
		b += a;
		a = tmp;
	}
	return b;
}

TEST_CASE("Recursioin testing", "[Fib]") {
	REQUIRE(fib(10) == 55);
	REQUIRE(fib_loop(10) == 55);
}