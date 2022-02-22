#pragma once
#include <string>
using std::string;
#include "caveJunction.h"

class CaveSystem
{
public:
	CaveSystem();
	CaveSystem(map<string, CaveJunction>& caveSystem);
	void addJunction(std::pair<string,CaveJunction> & caveJunction);

	friend std::ostream& operator<<(std::ostream& out, CaveSystem& a) { for (auto n : a._caveSystem) { out << n.first << n.second << std::endl; }; return out; };
	map<string,CaveJunction> returnCave();
	~CaveSystem(){}
private:
	map<string, CaveJunction> _caveSystem;
};

