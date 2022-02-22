#include "CaveSystem.h"

CaveSystem::CaveSystem() {

}

CaveSystem::CaveSystem(map<string, CaveJunction>& caveSystem) {
	_caveSystem = caveSystem;
}

void CaveSystem::addJunction(std::pair<string, CaveJunction>& caveJunction) {
	_caveSystem.insert(caveJunction);
}

map<string, CaveJunction> CaveSystem::returnCave() {
	return _caveSystem;
}