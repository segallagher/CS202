
#include "FilledBox.h"
#include "HollowBox.h"

#include <iostream>

int main()
{
	FilledBox a(5);
	a.draw();
	std::cout << std::endl;
	HollowBox b(5);
	b.draw();
}
