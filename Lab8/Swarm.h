#pragma once
#include <sstream>
using std::ostream;

class Swarm
{
public:
	static int objectCount;
	Swarm();
	void add(const int& value);
	~Swarm() { objectCount--; }
private:
	int num;

};