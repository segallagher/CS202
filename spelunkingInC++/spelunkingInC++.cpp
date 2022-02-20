#include <fstream>
using std::ifstream;
using std::ofstream;
#include "caveJunction.h"

void readCave() {

}

int main()
{
	string previousLocation = "2";
	string currentLocation = "1";
	map<string, CaveJunction> caveSystem{
		std::pair<string,CaveJunction>("1",CaveJunction("2","3","4")),
		std::pair<string,CaveJunction>("2",CaveJunction("1","3","4")),
		std::pair<string,CaveJunction>("3",CaveJunction("1","2","4")),
		std::pair<string,CaveJunction>("4",CaveJunction("1","3","2")),
	};
	caveSystem.at("1").printOptions(caveSystem,currentLocation,previousLocation);
}