#pragma once
#include <string>
using std::string;
#include "caveJunction.h"

class CaveSystem
{
public:
	CaveSystem();
	CaveSystem(map<string, CaveJunction>& caveSystem, string& startLocation, string& previousLocation);
	void addJunction(std::pair<string,CaveJunction> & caveJunction);
	void setStart(string& startLocation, string& previousLocation);
	string returnLocation();

	friend std::ostream& operator<<(std::ostream& out, CaveSystem& a) { for (auto n : a._caveSystem) { out << n.first << n.second << std::endl; }; return out; };
	map<string,CaveJunction> returnCave();
	void move();

	~CaveSystem(){}
private:
	map<string, CaveJunction> _caveSystem;
	string _currentLocation;
	string _previousLocation;
	std::vector<string> _haveVisited;
};

