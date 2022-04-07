#include "FilledBox.h"
void FilledBox::draw() const {
	for (int h = 0; h < get_height(); h++) {
		for (int w = 0; w < get_width(); w++) {
			std::cout << '*';
		}
		std::cout << std::endl;
	}
}
