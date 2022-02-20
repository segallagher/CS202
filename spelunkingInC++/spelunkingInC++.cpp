#include <fstream>
using std::ifstream;
using std::ofstream;
#include "caveJunction.h"

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
	move(currentLocation, previousLocation, caveSystem);
	move(currentLocation, previousLocation, caveSystem);
	move(currentLocation, previousLocation, caveSystem);
	move(currentLocation, previousLocation, caveSystem);
}