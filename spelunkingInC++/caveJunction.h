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
	CaveJunction(const string & d1, const string& d2, const string& d3);
	~CaveJunction(){}
	std::vector<string> printOptions(const map<string,CaveJunction> & caveSystem,const string & currentLocation, const string & previousLocation);

private:
	std::vector<string> _connections;
};

