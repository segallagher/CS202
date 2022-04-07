#include "HollowBox.h"

void drawSolid(const int & w) {
	for (int i = 0; i < w; i++) {
		std::cout << '*';
	}
}

void drawHollow(const int & w, const int & h) {
	for (int i = 0; i < h - 2; i++) {
		std::cout << '*';
		for (int k = 0; k < w - 2; k++) {
			std::cout << ' ';
		}
		std::cout << "*\n";
	}

}

void HollowBox::draw() const {
	drawSolid(get_width());
	std::cout << "\n";
	drawHollow(get_width(), get_height());
	drawSolid(get_width());
}

