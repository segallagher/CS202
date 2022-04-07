#include "CheckeredBox.h"

void CheckeredBox::draw() const{
	for (int i = 0; i < get_width() * get_height(); i++) {
		if (i % get_width() == 0) { std::cout << "\n"; }
		if (i % 2 == 0) {
			std::cout << 'x';
		}
		else {
			std::cout << ' ';
		}
	}
}