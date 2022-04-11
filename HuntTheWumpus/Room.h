#pragma once
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <sstream>

#include <iomanip>;

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
	const string readName() { return _roomName; }

	void setNum(const int& num) { _roomNum = num; }
	void setHazard(const string& str) { _hazard = str; }
	void setConnections(const vector<int>& con) { _connections = con; }
	void appendConnections(const int& num) { _connections.push_back(num); }
	void setName(const string& str) { _roomName = str; }

	friend std::ostream& operator<<(std::ostream& out, const Room& object) { out << "Name: " << std::setw(3) << object._roomName << "\tIndex: " << std::setw(3) << object._roomNum << "\tConnections: "; for (auto n : object._connections) { out << std::setw(3) << n << " "; } return out; }

private:
	vector<int> _connections;
	string _roomName;
	int _roomNum;
	string _hazard;
};

