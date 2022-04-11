#pragma once
#include <string>
using std::string;
#include <vector>
using std::vector;

class Room
{
public:
	Room() : _roomNum(-1), _hazard("") {}
	Room(const int& num) : _roomNum(num), _hazard("") {}
	Room(const int& num, const string& str) : _roomNum(num), _hazard(str) {}
	~Room() {}

	const int readNum() { return _roomNum; }
	const string readHazard() { return _hazard; }
	const vector<int> readConnections() { return _connections; }

	void setNum(const int& num) { _roomNum = num; }
	void setHazard(const string& str) { _hazard = str; }
	void setConnections(const vector<int>& con) { _connections = con; }

private:
	vector<int> _connections;
	int _roomNum;
	string _hazard;
};

