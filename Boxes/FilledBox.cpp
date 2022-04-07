#include "FilledBox.h"
void FilledBox::draw() const {
	for (int h = 0; h < _height; h++) {
		for (int w = 0; w < _width; w++) {
			std::cout << '*';
		}
		std::cout << std::endl;
	}
}
