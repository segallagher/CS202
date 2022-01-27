#include <iostream>
#include <vector>
#include "Stopwatch.h"

int main()
{
	Stopwatch funky;
	std::vector<int> dummy;
	funky.start();

	funky.stop();
	std::cout << funky.readMilliseconds().count() << " Milliseconds" << std::endl;
	std::cout << funky.readSeconds() << " Seconds" << std::endl;
}
