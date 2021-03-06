#include "CaveSystem.h"

CaveSystem::CaveSystem() {

}

CaveSystem::CaveSystem(map<string, CaveJunction>& caveSystem, string& startLocation, string& previousLocation) {
	_currentLocation = startLocation;
	_previousLocation = previousLocation;
	_caveSystem = caveSystem;
}

void CaveSystem::addJunction(std::pair<string, CaveJunction>& caveJunction) {
	_caveSystem.insert(caveJunction);
}

void CaveSystem::setStart(string& startLocation, string& previousLocation) {
	_currentLocation = startLocation;
	_previousLocation = previousLocation;
}

map<string, CaveJunction> CaveSystem::returnCave() {
	return _caveSystem;
}

void CaveSystem::move() {
	string direction = _caveSystem.at(_currentLocation).printOptions(_caveSystem, _currentLocation, _previousLocation,_haveVisited);
	if (std::find(_haveVisited.begin(), _haveVisited.end(), _currentLocation) == _haveVisited.end()) {
		_haveVisited.push_back(_currentLocation);
	}
	if (direction == "") {
		CaveSystem::move();
	}
	else {
		_previousLocation = _currentLocation;
		_currentLocation = direction;
	}
	return;
}

string CaveSystem::returnLocation() {
	return _currentLocation;
}