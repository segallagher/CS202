#include "CaveSystem.h"

vector<Room> createDummyRooms(const int & size) {
	vector<Room> output;
	for (int i = 0; i < size; i++) {
		output.push_back(Room(i + 1));

		// This could be written in a file and read instead
		switch (i)
		{
		case 0:
			output.at(i).setConnections(vector<int> {2, 5, 8 });
			break;
		case 1:
			output.at(i).setConnections(vector<int> { 1,3,10 });
			break;
		case 2:
			output.at(i).setConnections(vector<int> { 2,4,12});
			break;
		case 3:
			output.at(i).setConnections(vector<int> { 3,5,14});
			break;
		case 4:
			output.at(i).setConnections(vector<int> { 1,4,6});
			break;
		case 5:
			output.at(i).setConnections(vector<int> { 5,7,15});
			break;
		case 6:
			output.at(i).setConnections(vector<int> { 6,8,17});
			break;
		case 7:
			output.at(i).setConnections(vector<int> { 1,7,9});
			break;
		case 8:
			output.at(i).setConnections(vector<int> { 8,10,18});
			break;
		case 9:
			output.at(i).setConnections(vector<int> { 2,9,11});
			break;
		case 10:
			output.at(i).setConnections(vector<int> { 10,12,19});
			break;
		case 11:
			output.at(i).setConnections(vector<int> { 3,11,13});
			break;
		case 12:
			output.at(i).setConnections(vector<int> { 12,14,20});
			break;
		case 13:
			output.at(i).setConnections(vector<int> { 4,13,15});
			break;
		case 14:
			output.at(i).setConnections(vector<int> { 6,14,16});
			break;
		case 15:
			output.at(i).setConnections(vector<int> { 15,17,20});
			break;
		case 16:
			output.at(i).setConnections(vector<int> { 7,16,18});
			break;
		case 17:
			output.at(i).setConnections(vector<int> { 9,17,19});
			break;
		case 18:
			output.at(i).setConnections(vector<int> { 11,18,20});
			break;
		case 19:
			output.at(i).setConnections(vector<int> { 13,16,19});
			break;
		default:
			break;
		}
	}
	return output;
}

vector<Room> shuffleRooms(const int & size, const mt19937 & seed,const vector<Room> & rooms){
	vector<int> range;
	for (int i = 1; i < size + 1; i++) { range.push_back(i); }
	std::shuffle(range.begin(), range.end(), std::default_random_engine(seed));

	for (int i = 1; i < size + 1; i++) {

	}
}

void CaveSystem::generateCave() {
	//allows for generating random number between 1 and _size with dist(generator)
	random_device rd;
	mt19937 generator{rd()};
	std::uniform_int_distribution<int> dist{ 1, _size };

	//creates range of available values, numbers will be removed as availability is taken up
	vector<int> range;
	for (int i = 1; i < _size + 1; i++) { range.push_back(i); }

	vector<Room> shuffledRooms = shuffleRooms(_size,generator,createDummyRooms(_size));
}