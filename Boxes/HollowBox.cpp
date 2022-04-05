#include "HollowBox.h"

void drawSolid(const int & w) {
	for (int i = 0; i < w; i++) {
		std::cout << '*';
	}
	std::cout << std::endl;
}

void drawHollow(const int & w, const int & h) {
	for (int i = 0; i < h; i++) {
		std::cout << '*';
		for (int k = 0; k < w - 2; k++) {
			std::cout << ' ';
		}
		std::cout << '*';
	}

}

void HollowBox::draw() const {
	drawSolid(_width);
	drawHollow(_width, _height);
	drawSolid(_width);
}

