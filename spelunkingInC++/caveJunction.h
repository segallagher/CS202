#pragma once
#include <iostream>
#include <string>
using std::string;
#include <map>
using std::map;
#include <vector>

class CaveJunction
{
public:
	CaveJunction(const string& d1, const string& d2, const string& d3);
	~CaveJunction() {}
	string printOptions(const map<string, CaveJunction>& caveSystem, const string& currentLocation, const string& previousLocation);

	friend std::ostream& operator<<(std::ostream& out, CaveJunction& a) {out << "," << a._connections.at(0) << "," << a._connections.at(1) << "," << a._connections.at(2); return out; };
private:
	std::vector<string> _connections;
};

