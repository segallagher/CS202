#pragma once
#include "Room.h"
#include <random>
using std::mt19937;
using std::random_device;
#include <iostream>

class CaveSystem
{
public:
	CaveSystem() : _size(20),_remainingArrows(5) {}
	//CaveSystem(const int & num) : _size(num) {}
	~CaveSystem() {}

	void generateCave();
	void nextAction();
	void displayIntro();

	void debugPrintCave();

	int returnSize() { return _size; }
	vector<Room> returnCave() { return _cave; }

private:
	void locateCharacters();

	int _size;
	vector<Room> _cave;

	int _wumpusLocation;
	int _playerLocation;
	int _remainingArrows;
};

