#pragma once
#include <string>
using std::string;
#include <map>
using std::map;

class CaveJunction
{
public:
	CaveJunction(const string & d1, const string& d2, const string& d3);
	~CaveJunction(){}
	void printOptions(const string & entrance, const map<string,CaveJunction> & caveSystem);

private:
	string _d1;
	string _d2;
	string _d3;
};

