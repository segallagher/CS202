#include "FilledBox.h"
std::ostream& FilledBox::print(std::ostream& a ) const {
	for (int h = 0; h < getHeight(); h++) {
		for (int w = 0; w < getWidth(); w++) {
			a << '*';
		}
		a << '\n';
	}
	return a;
}
