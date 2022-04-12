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
	vector<Room> shuffledRooms = rooms;
	for (int i = 0; i < size; i++) {
		shuffledRooms.at(i).setName(std::to_string(range.at(i)));
	}
	return shuffledRooms;
}

void placeHazardType(const int & size, mt19937& seed, const int & count, vector<Room> & output,const string & type) {
	std::uniform_int_distribution<int> dist{ 0, size - 1 };
	int tmp = 0;
	while (tmp < count) {
		int a = dist(seed);
		if (output.at(a).readHazard() == "") {
			output.at(a).setHazard(type);
			tmp++;
		}
	}
}

void CaveSystem::locateCharacters() {
	for (auto n : _cave) {
		if (n.readHazard() == "wumpus") { _wumpusLocation = n.readNum(); }
		else if (n.readHazard() == "player") { _playerLocation = n.readNum(); }
	}
}

vector<Room> populateCave(const int& size, mt19937& seed, const vector<Room>& rooms, const int & numPits, const int & numBats) {
	vector<Room> output = rooms;
	std::uniform_int_distribution<int> dist{ 0, size-1};
	placeHazardType(size, seed, numPits, output, "pit");
	placeHazardType(size, seed, numBats, output, "bats");
	placeHazardType(size, seed, 1, output, "wumpus");
	placeHazardType(size, seed, 1, output, "player");
	return output;
}

void CaveSystem::generateCave() {
	int numPits = 2;
	int numBats = 2;

	//allows for generating random number between 1 and _size with dist(generator)
	random_device rd;
	mt19937 generator{rd()};
	std::uniform_int_distribution<int> dist{ 1, _size };

	_cave = populateCave(_size, generator, shuffleRooms(_size,generator,createDummyRooms(_size)), numPits, numBats);
	locateCharacters();
	debugPrintCave();

}



void CaveSystem::nextAction() {

}

void CaveSystem::displayIntro() {
	std::cout << "You've come into this cave system looking\nto vanquish the Wumpus\nThere are risks to this hunt though\n1. Bottomless Pits from which you will never escape\n2. Super Bats which will bring you somewhere random\n3. The Wumpus, who if it finds you will eat you\n\nCareful where you shoot however\nfor the wumpus knows the sound of the bowstring\nand you only brought " << _remainingArrows << " arrows" << std::endl;
	
}

void CaveSystem::debugPrintCave() {
	for (auto n : _cave) {
		std::cout << n << std::endl;
	}
	std::cout << "Wumpus Location: " << std::setw(3) << _wumpusLocation << std::endl;
	std::cout << "Player Location: " << std::setw(3) << _playerLocation << std::endl;
}