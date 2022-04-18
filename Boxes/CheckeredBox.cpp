#include "CheckeredBox.h"

std::ostream& CheckeredBox::print(std::ostream& os) const{
	std::string characters = "x ";
	for (int k = 0; k < getHeight(); k++) {
		for (int i = 0; i < getWidth(); i++) {
			os << characters.at((i % 2 + k % 2) % 2);
		}
		os << '\n';
	}
	return os;
}