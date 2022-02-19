#include <iostream>
#include "Something.h"

int main()
{
	std::list<int> a = { 1,15,7,86,10};
	Something alpha (a);
	std::cout << alpha << std::endl;
	alpha.sort();
	std::cout << alpha << std::endl;
	alpha.insertion(40);
	std::cout << alpha << std::endl;
	alpha.stack(68);
	std::cout << alpha << std::endl;
	alpha.queue(69);
	std::cout << alpha << std::endl;
}
