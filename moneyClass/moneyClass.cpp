#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
//#include <catch2/catch.hpp>
#include "catch.hpp"
#include <sstream>      // for std::ostringstream

#include "Money.hpp"
#include "Money.hpp"   // Double inclusion test

TEST_CASE("Money ctors and operator<<") {
	const Money con0;
	const Money con1(2);
	const Money con2(2.02);
	const Money con3(-3.03);
	std::ostringstream os;
	os << con0;
	REQUIRE(os.str() == "$0.00");
	os.str(""); //reset output holder
	os << con1;
	REQUIRE(os.str() == "$0.02");

	os.str(""); //reset output holder
	os << con2;
	REQUIRE(os.str() == "$2.02");

	os.str("");
	os << con3;
	REQUIRE(os.str() == "-$3.03");

	const Money con4(7.072);
	os.str("");
	os << con4;
	REQUIRE(os.str() == "$7.07");

	const Money con5(7.077);
	os.str("");
	os << con5;
	REQUIRE(os.str() == "$7.08");

	const Money con6(-7.072);
	os.str("");
	os << con6;
	REQUIRE(os.str() == "-$7.07");

	const Money con7(-7.077);
	os.str("");
	os << con7;
	REQUIRE(os.str() == "-$7.08");
}

TEST_CASE("Money relational operators") {
	const Money m0;
	const Money m1(1);

	REQUIRE((m0 == m0));
	REQUIRE(!(m0 == m1));

	REQUIRE(!(m0 != m0));
	REQUIRE((m0 != m1));

	REQUIRE(!(m0 < m0));
	REQUIRE((m0 < m1));
	REQUIRE(!(m1 < m0));

	REQUIRE((m0 <= m0));
	REQUIRE((m0 <= m1));
	REQUIRE(!(m1 <= m0));

	REQUIRE(!(m0 > m0));
	REQUIRE(!(m0 > m1));
	REQUIRE((m1 > m0));

	REQUIRE((m0 >= m0));
	REQUIRE(!(m0 >= m1));
	REQUIRE((m1 >= m0));
}

TEST_CASE("Money arithmetic operators") {
	const Money m0;
	Money m1(1);
	Money m2(2);
	const Money mc1(m1);
	const Money mc2(2);

	m1 -= mc1;
	REQUIRE(m1 == m0);

	m1 += mc1;
	REQUIRE(m1 == mc1);

	m1 *= 2.0;
	REQUIRE(m1 == mc2);

	m1 /= 2.0;
	REQUIRE(m1 == mc1);

	REQUIRE(mc1 + mc1 == mc2);

	REQUIRE(mc1 - mc1 == m0);

	REQUIRE(2 * mc1 == mc2);

	REQUIRE(mc1 * 2 == mc2);

	REQUIRE(mc2 / 2 == mc1);

	Money m12;
	m12 = mc1;
	REQUIRE(m12 == mc1);

	(m2 -= mc1) = m0;
	REQUIRE(m2 == m0);

	(m2 += mc1) = m0;
	REQUIRE(m2 == m0);

	m2 = Money(4.2);
	(m2 /= 2.0) = m0;
	REQUIRE(m2 == m0);

	m2 = Money(4.2);
	(m2 *= 2.0) = m0;
	REQUIRE(m2 == m0);
}