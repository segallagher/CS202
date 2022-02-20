#include <fstream>
using std::ifstream;
using std::ofstream;
#include "caveJunction.h"

void writeCaveFile(map<string, CaveJunction>& caveSystem,const string& fileName) {
	ofstream file(fileName,std::ios::out | std::ios::binary);
	if (!file) {
		std::cout << "Error opening " << fileName << std::endl;
	}
	for (auto n : caveSystem) {
		//file << n.first << " " << n.second << std::endl;
		file.write(reinterpret_cast<const char*>(n.first.c_str()),sizeof(string));
	}
}

void readCave() {

}

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

int main()
{
	string previousLocation = "2";
	string currentLocation = "1";
	//CaveJunction names must be all lower case
	map<string, CaveJunction> caveSystem{
		std::pair<string,CaveJunction>("1",CaveJunction("2","","4")),
		std::pair<string,CaveJunction>("2",CaveJunction("1","3","4")),
		std::pair<string,CaveJunction>("3",CaveJunction("","2","4")),
		std::pair<string,CaveJunction>("4",CaveJunction("1","3","2")),
	};
	writeCaveFile(caveSystem, "joe.txt");

}