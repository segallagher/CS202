#include <fstream>
using std::ifstream;
using std::ofstream;
#include "caveJunction.h"
#include "CaveSystem.h"
#include <sstream>

void writeCaveFile(CaveSystem& caveSystem,const string& fileName) {
	ofstream file(fileName,std::ios::out);
	if (!file) {
		std::cout << "Error opening " << fileName << std::endl;
	}
	string delim = ",";
	for (auto n : caveSystem.returnCave()) {
		file << n.first << n.second << std::endl;
	}
}

map<string,CaveJunction> readCaveFile(const string & fileName) {
	ifstream file(fileName,std::ios::in);
	if (!file) {
		std::cout << "Error opening " << fileName << std::endl;
	}
	map<string, CaveJunction> caveSystem;
	string line;

	while (!file.eof()) {
		std::getline(file, line);
		std::stringstream intermediate(line);
		std::vector<string> tokens;
		string k;

		while (std::getline(intermediate, k, ',')) {
			tokens.push_back(k);
		}
		if (tokens.size() == 0) {
			break;
		}
		caveSystem.insert(std::pair<string, CaveJunction>(tokens[0],CaveJunction(tokens[1],tokens[2],tokens[3])));
	}
	return caveSystem;
}
#if 0
void move(string& currentLocation, string & previousLocation, map<string,CaveJunction> & caveSystem) {
	string direction = caveSystem.at(currentLocation).printOptions(caveSystem, currentLocation, previousLocation);
	if (direction == "") {
		move(currentLocation, previousLocation, caveSystem);
	}
	else {
		previousLocation = currentLocation;
		currentLocation = direction;
	}
	return;
}
#endif
int main()
{
	string previousLocation = "2";
	string currentLocation = "1";
	//CaveJunction names must be all lower case
	map<string, CaveJunction> caveSystemBase{
		std::pair<string,CaveJunction>("1",CaveJunction("2","","4")),
		std::pair<string,CaveJunction>("2",CaveJunction("1","3","4")),
		std::pair<string,CaveJunction>("3",CaveJunction("","2","4")),
		std::pair<string,CaveJunction>("4",CaveJunction("1","3","2")),
	};
	CaveSystem caveSystem(caveSystemBase,currentLocation,previousLocation);
	std::cout << caveSystem << std::endl;
	writeCaveFile(caveSystem, "joe.txt");
	map<string,CaveJunction> a = readCaveFile("joe.txt");
	CaveSystem caveSystem2(a,currentLocation,previousLocation);
	std::cout << caveSystem2 << std::endl;
	caveSystem2.move();
}