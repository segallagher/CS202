#include "CaveSystem.h"

Room createRoom(const int &room ,vector<int> & range, mt19937 &generator) {
	const int CONNECTIONS = 3;
	std::uniform_int_distribution<int> dist{ 1,(int)range.size() };

	Room tmp(room);

	//	!!!WARNING!!!
	//	May need to retry entire approch to room
	//  Rooms need to create connections to other rooms that do not exist yet with this method
	//  Perhaps create dummy rooms and update their _connections

	for (int i = 1; i < CONNECTIONS; i++) {
		int test = dist(generator);
		vector<int> connect = tmp.readConnections();
		if (std::find(connect.begin(), connect.end(), test) != connect.end()) {
			tmp.appendConnections(test);
		}
		else {
			std::cout << "Decrimenting" << std::endl;
			//i--;
		}
	}
	std::cout << tmp << std::endl;
	return Room();
}

void CaveSystem::generateCave() {
	//allows for generating random number between 1 and _size with dist(generator)
	random_device rd;
	mt19937 generator{rd()};
	std::uniform_int_distribution<int> dist{ 1, _size };

	//creates range of available values, numbers will be removed as availability is taken up
	vector<int> range;
	for (int i = 1; i < _size + 1; i++) { range.push_back(i); }

	for (int k = 1; k < _size + 1; k++) {
		_cave.push_back(createRoom(k,range,generator));
	}
}