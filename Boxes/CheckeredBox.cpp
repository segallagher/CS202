#include "CheckeredBox.h"

void CheckeredBox::draw() const{
	std::string characters = "x ";
	for (int k = 0; k < get_height(); k++) {
		for (int i = 0; i < get_width(); i++) {
			std::cout << characters.at((i % 2 + k % 2) % 2);
		}
		std::cout << '\n';
	}
}