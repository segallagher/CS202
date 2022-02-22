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

int main()
{
	string previousLocation = "cave river";
	string currentLocation = "damp room";
	//CaveJunction names must be all lower case
	map<string, CaveJunction> caveSystemBase{
		std::pair<string,CaveJunction>("damp room",CaveJunction("cave river","","4")),
		std::pair<string,CaveJunction>("cave river",CaveJunction("damp room","3","4")),
		std::pair<string,CaveJunction>("3",CaveJunction("","cave river","4")),
		std::pair<string,CaveJunction>("4",CaveJunction("damp room","3","cave river")),
	};
	CaveSystem caveSystem(caveSystemBase,currentLocation,previousLocation);
	std::cout << caveSystem << std::endl;
	writeCaveFile(caveSystem, "joe.txt");
	map<string,CaveJunction> a = readCaveFile("joe.txt");
	CaveSystem caveSystem2(a,currentLocation,previousLocation);
	std::cout << caveSystem2 << std::endl;
	caveSystem2.move();
	caveSystem2.move();
	caveSystem2.move();
}