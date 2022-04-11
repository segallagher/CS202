#pragma once
#include "Room.h"
#include <random>
using std::mt19937;
using std::random_device;
#include <iostream>

class CaveSystem
{
public:
	CaveSystem() : _size(20) {}
	//CaveSystem(const int & num) : _size(num) {}
	~CaveSystem() {}

	void generateCave();

	int returnSize() { return _size; }
	vector<Room> returnCave() { return _cave; }

private:
	int _size;
	vector<Room> _cave;
};

