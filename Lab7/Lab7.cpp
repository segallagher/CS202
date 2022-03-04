#include <iostream>
#include "NewVector.h"

int main()
{
	vector<int> j = { 1,2,3,4,5,6,7,8,9,10 };
	NewVector a(j);
	a.append(57);
	std::cout << a << std::endl;
}