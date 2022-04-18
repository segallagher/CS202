#include "HollowBox.h"

void drawSolid(const int & w, std::ostream& os) {
	for (int i = 0; i < w; i++) {
		os << '*';
	}
}

void drawHollow(const int & w, const int & h, std::ostream& os) {
	for (int i = 0; i < h - 2; i++) {
		std::cout << '*';
		for (int k = 0; k < w - 2; k++) {
			os << ' ';
		}
		os << "*\n";
	}

}

std::ostream& HollowBox::print(std::ostream& os) const {
	drawSolid(getWidth(),os);
	os << "\n";
	drawHollow(getWidth(), getHeight(),os);
	drawSolid(getWidth(),os);
	return os;
}

