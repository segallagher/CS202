
#include "FilledBox.h"
#include "HollowBox.h"
#include "CheckeredBox.h"

#include <iostream>
#include <vector>
using std::vector;

int main()
{
	vector< Box * > warehouse;
	//need to use unique_ptr instead of new
	warehouse.push_back(new FilledBox());
	warehouse.push_back(new HollowBox());
	warehouse.push_back(new CheckeredBox());

	for (auto n : warehouse) {
		n->draw();
		std::cout << std::endl;
	}
}
