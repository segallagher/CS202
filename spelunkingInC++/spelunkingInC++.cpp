#include <fstream>
using std::ifstream;
using std::ofstream;
#include "caveJunction.h"
#include "CaveSystem.h"
#include <sstream>

void writeCaveFile(CaveSystem& caveSystem,const string& fileName,const string & startLocation,const string & previousLocation) {
	ofstream file(fileName,std::ios::out);
	if (!file) {
		std::cout << "Error opening " << fileName << std::endl;
	}
	file << startLocation << "," << previousLocation << std::endl;
	for (auto n : caveSystem.returnCave()) {
		file << n.first << n.second << std::endl;
	}
}

map<string,CaveJunction> readCaveFile(const string & fileName, string & startLocation, string & previousLocation) {
	ifstream file(fileName,std::ios::in);
	if (!file) {
		std::cout << "Error opening " << fileName << std::endl;
	}
	map<string, CaveJunction> caveSystem;
	string line;
	std::getline(file, line);
	std::stringstream headerIntermediate(line);
	string g;
	std::vector<string> headerTokens;
	while (std::getline(headerIntermediate, g, ',')) {
		headerTokens.push_back(g);
	}
	startLocation = headerTokens[0];
	previousLocation = headerTokens[1];

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

void createCave(const string & fileName) {
	//CaveJunction names must be all lower case
	//Last connection slot of CaveJunction() must be filled
	string previousLocation = "cave river";
	string currentLocation = "damp room";
	map<string, CaveJunction> caveSystemBase{
		std::pair<string,CaveJunction>("damp room",CaveJunction("cave river","","large cavern")),
		std::pair<string,CaveJunction>("cave river",CaveJunction("damp room","fast flowing water","river head")),
		std::pair<string,CaveJunction>("river head",CaveJunction("","cave river","mossy chamber")),
		std::pair<string,CaveJunction>("mossy chamber",CaveJunction("","","river head")),
		std::pair<string,CaveJunction>("fast flowing water",CaveJunction("cave river","large cavern","waterfall")),
		std::pair<string,CaveJunction>("waterfall",CaveJunction("","","fast flowing water")),
		std::pair<string,CaveJunction>("large cavern",CaveJunction("damp room","bat roost","fast flowing water")),
		std::pair<string,CaveJunction>("bat roost",CaveJunction("large cavern","tight passage","large slope")),
		std::pair<string,CaveJunction>("tight passage",CaveJunction("old campfire","large slope","bat roost")),
		std::pair<string,CaveJunction>("old campfire",CaveJunction("tight passage","","root filled passage")),
		std::pair<string,CaveJunction>("root filled passage",CaveJunction("old campfire","windy room","wobbling stalagtites")),
		std::pair<string,CaveJunction>("large slope",CaveJunction("bat roost","tight passage","wobbling stalagtites")),
		std::pair<string,CaveJunction>("wobbling stalagtites",CaveJunction("large slope","root filled passage","windy room")),
		std::pair<string,CaveJunction>("windy room",CaveJunction("wobbling stalagtites","root filled passage","cave opening")),
		std::pair<string,CaveJunction>("cave opening",CaveJunction("windy room","","outside")),
		std::pair<string,CaveJunction>("outside",CaveJunction("","","cave opening")),
	};
	CaveSystem caveSystem(caveSystemBase, currentLocation, previousLocation);
	std::cout << "Cave created" << std::endl;
	writeCaveFile(caveSystem, fileName,currentLocation,previousLocation);
	std::cout << "Cave Written" << std::endl;
}

CaveSystem readCave(const string & fileName) {
	string currentLocation;
	string previousLocation;
	map<string,CaveJunction> cave = readCaveFile(fileName, currentLocation, previousLocation);
	std::cout << "Cave read" << std::endl;
	CaveSystem createdCaves(cave, currentLocation, previousLocation);
	std::cout << "Cave system created" << std::endl;
	return createdCaves;
}

int main()
{
	const string fileName = "joe.txt";
	createCave(fileName);
	CaveSystem caves = readCave(fileName);
	std::cout << "Starting Game" << std::endl << std::endl;
	caves.move();
}