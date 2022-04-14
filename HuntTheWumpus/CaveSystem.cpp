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
	_seed = generator;
	std::uniform_int_distribution<int> dist{ 1, _size };

	_cave = populateCave(_size, generator, shuffleRooms(_size,generator,createDummyRooms(_size)), numPits, numBats);
	locateCharacters();
	_gameState = std::make_pair(true, true);

	debugPrintCave();

}

void CaveSystem::displayHazards() {
	vector<int> connections = _cave.at(_playerLocation-1).readConnections();
	for (auto n : connections) {
		if (_cave.at(n-1).readHazard() == "bats") {
			std::cout << "You hear the screeches of bats" << std::endl;
		}
		else if (_cave.at(n-1).readHazard() == "pit") {
			std::cout << "You feel a breeze" << std::endl;
		}
		else if (_cave.at(n-1).readNum() == _wumpusLocation) {
			std::cout << "You smell a wumpus" << std::endl;
		}
		
	}
}

void CaveSystem::move(const string& input) {

	std::cout << "Where to? ";
	string motion;
	std::getline(std::cin, motion, '\n');

	try {
		std::stoi(motion);
	}
	catch (std::invalid_argument) {
		std::cout << "Please enter a valid input.\n" << std::endl;
		return;
	}


	vector<int> vec;
	for (auto n : _cave.at(_playerLocation - 1).readConnections()) {
		vec.push_back(std::stoi(_cave.at(n - 1).readName()));
	}
	std::vector<int>::iterator it;
	it = std::find(vec.begin(), vec.end(), std::stoi(motion));

	if (it != vec.end()) {
		int targetLocation;
		for (auto n : _cave) {
			if (n.readName() == motion) {
				targetLocation = n.readNum();
			}
		}
		setPlayerPosition(targetLocation);
		checkHazard();
		std::cout << std::endl;
		return;
	}
	else {
		std::cout << "Enter valid Input" << std::endl;
		processAction(input);
	}
}

void CaveSystem::checkHazard() {//////////////////////////////////////////
	if (_cave.at(_playerLocation - 1).readNum() == _cave.at(_wumpusLocation - 1).readNum()) {
		std::cout << "The Wumpus has eaten you" << std::endl;
		_gameState = std::make_pair(false, false);
	}
	else if (_cave.at(_playerLocation - 1).readHazard() == "pit") {
		std::cout << "You fall to your death" << std::endl;
		_gameState = std::make_pair(false, false);
	}
	else if (_cave.at(_playerLocation - 1).readHazard() == "bats") {
		std::cout << "The bats carry you somwhere random" << std::endl;
		std::uniform_int_distribution<int> dist{ 1,_size };
		// now its not all based on the same seed, unfortunate
		random_device rd;
		mt19937 gen{ rd() };
		int target = dist(gen);
		setPlayerPosition(_cave.at(target - 1).readNum());
		checkHazard();
	}
}

void CaveSystem::setWumpusPosition(const int& num) { 
	_wumpusLocation = num; 
}

void CaveSystem::moveWumpus() {
	std::uniform_int_distribution<int> range{ 0, 2 };
	int offset = range(_seed);
	vector<int> targets = _cave.at(_wumpusLocation - 1).readConnections();

	std::cout << "Wumpus targets ";
	for (auto n : targets) {
		std::cout << n << " ";
	}
	std::cout << std::endl;
	std::cout << "New Location: " << targets.at(offset) << std::endl;
	setWumpusPosition(targets.at(offset));
	debugPrintCave();

}

int CaveSystem::nameToIndex(const string& name) {
	for (auto n : _cave) {
		if (n.readName() == name) {
			return n.readNum();
		}
	}
	return -1;
}

bool checkPath(const vector<int> & preConnections,const int & postLocation) {
	for (auto n : preConnections) {
		if (n == postLocation) {
			return true;
		}
	}
	return false;
}

bool CaveSystem::checkShot(const int & location) {
	if (_cave.at(location - 1).readHazard() == "wumpus") {
		return true;
	}
	return false;
}

void CaveSystem::shoot(const string& input) {
	const int MAXRANGE = 1;

	std::cout << "Where do you aim? ";
	string motion;
	std::getline(std::cin, motion, '\n');
	std::cout << "\nYou Shoot" << std::endl;//
	vector<int> targets;
	std::stringstream ss(motion);
	string tmp;
	while (std::getline(ss, tmp, '-')) {
		try {
			std::stoi(tmp);
		}
		catch (std::invalid_argument) {
			std::cout << "Please enter a valid input.\n" << std::endl;
			return;
		}
		targets.push_back(std::stoi(tmp));
	}
	if (targets.size() > MAXRANGE) {
		std::cout << "You cant shoot that far." << std::endl;
		return;
	}

	if (checkShot(_cave.at(nameToIndex(std::to_string(targets.at(0))) - 1).readNum())) {
		std::cout << "Hit" << std::endl;
	}
	else {
		std::cout << "Miss" << std::endl;
		moveWumpus();
	}
#if 0


	// Put player location and targets in order into a vector for further processing
	vector<int> locations = { _playerLocation };	//indexes
	//locations.push_back(_playerLocation);
	for (auto n : targets) {
		locations.push_back(nameToIndex(std::to_string(n)));
	}

#if 0
	for (int i = 1; i < locations.size(); i++) {
		std::cout << "Scanning" << std::endl;//
		vector<int> vec;	// current target's connections
		std::cout << locations.at(i) << " : ";
		//add locations of area the arrow just left
		for (auto n : _cave.at(locations.at(i - 1) - 1).readConnections()) {
			vec.push_back(std::stoi(_cave.at(n - 1).readName()));
			std::cout << n << " ";
		}
		std::cout << std::endl;
		std::vector<int>::iterator it;
		it = std::find(vec.begin(), vec.end(), nameToIndex(std::to_string(targets.at(i - 1))));
		std::cout << "Bruagana " << nameToIndex(std::to_string(targets.at(i - 1))) << std::endl;//
		//std::cout << *it << std::endl;//
		if (it != vec.end()) {
			std::cout << "It Flies" << std::endl;//
			if (checkShot(*it)) {
				//set gameover, win
				std::cout << "You Hit" << std::endl;//
				_gameState = std::make_pair(false, true);
				return;
			}
		}
		else {
			std::cout << "It Clatters" << std::endl;//

		}
	}
#endif
	for (int i = 1; i < locations.size(); i++) {
		std::cout << "Current Location: " << _cave.at(locations.at(i)).readName() << std::endl;
		std::cout << "Current Location Connections: ";
		for (auto n : _cave.at(locations.at(i - 1)).readConnections()) {
			std::cout << n << " ";
		}
		std::cout << std::endl;
		//std::cout << _cave.at(locations.at(i)).readName() << " " << _cave.at(locations.at(i)).readName() << std::endl;
	
		if (checkPath(_cave.at(locations.at(i - 1)).readConnections(), _cave.at(locations.at(i)).readNum())) {
			std::cout << "in" << std::endl;
#if 0			
			for (auto n : _cave.at(locations.at(i-1)).readConnections()) {
				std::cout << n << " ";
			}
			std::cout << ": " << _cave.at(locations.at(i)).readNum() << std::endl;

			if (checkShot(_cave.at(locations.at(i-1)).readNum())) {
				std::cout << _cave.at(locations.at(i-1)).readName() << " Killed" << std::endl;
			}
			else {
				std::cout << _cave.at(locations.at(i-1)).readName() << " Missed" << std::endl;
			}
#endif
		}
		else {
			std::cout << _cave.at(locations.at(i-1)).readName() << " Remember Better" << std::endl;
		}
	}
#endif
}

void CaveSystem::processAction(const string & input) {
	if (input == "s") {
		shoot(input);
	}
	else if (input == "m") {
		move(input);
	}
	std::cout << std::endl;
	return;
}

string CaveSystem::promptAction() {
	std::cout << "You are in room " << _cave.at(_playerLocation - 1).readName() << ".\nTunnels lead to ";
	for (int i = 0; i < _cave.at(_playerLocation - 1).readConnections().size(); i++) {
		std::cout << _cave.at(_cave.at(_playerLocation - 1).readConnections().at(i) - 1).readName();
		if(i < _cave.at(_playerLocation - 1).readConnections().size() - 1){std::cout << ", "; }
	}
	std::cout << "." << std::endl;
	std::cout << "Shoot or Move (S-M)? ";
	string input;
	std::getline(std::cin, input,'\n');

	string dummy;
	for (auto n : input) { dummy.push_back(std::tolower(n)); }
	input = dummy;
	
	if (input == "s") { return input; }
	else if (input == "m") { return input; }
	return "";
}

void CaveSystem::nextAction() {
	displayHazards();
	processAction(promptAction());
}

void CaveSystem::displayIntro() {
	std::cout << "You've come into this cave system looking\nto vanquish the Wumpus\nThere are risks to this hunt though\n1. Bottomless Pits from which you will never escape\n2. Super Bats which will bring you somewhere random\n3. The Wumpus, who if it finds you will eat you\n\nCareful where you shoot however\nfor the wumpus knows the sound of the bowstring\nand you only brought " << _remainingArrows << " arrows\n" << std::endl;
	std::cout << "You can move by entering M, then you will be\nprompted for where you wish to move.\nYou can shoot by entering S, then you will be\nprompted to enter your target\n" << std::endl; //You have a range of 3 units\nEnter targets in the form 1 or 1-2 or 1-2-3\nWhere 1,2,3 are locations in the cave\nBe careful to know where you are aiming\n" << std::endl;
}

void CaveSystem::startGame() {
	while (_gameState.first == true) {
		nextAction();
	}
}

void CaveSystem::debugPrintCave() {
	for (auto n : _cave) {
		std::cout << n << std::endl;
	}
	std::cout << "Wumpus Location: " << std::setw(3) << _wumpusLocation << std::endl;
	std::cout << "Player Location: " << std::setw(3) << _playerLocation << std::endl;
}