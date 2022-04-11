#include "CaveSystem.h"

void CaveSystem::generateCave() {
	random_device rd;
	mt19937 generator{rd()};
	std::uniform_int_distribution<int> dist{ 1, _size };
	std::cout << dist(generator) << std::endl;
}