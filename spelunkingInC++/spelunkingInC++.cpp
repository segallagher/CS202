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
	//CaveJunction names must be all lower case, last connection slot of CaveJunction() must be filled
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
	CaveSystem caveSystem(caveSystemBase,currentLocation,previousLocation);
	std::cout << "Cave created" << std::endl;
	writeCaveFile(caveSystem, "joe.txt");
	std::cout << "Cave Written" << std::endl;
	map<string,CaveJunction> a = readCaveFile("joe.txt");
	std::cout << "Cave read" << std::endl;
	CaveSystem caveSystem2(a,currentLocation,previousLocation);
	std::cout << "Cave system created" << std::endl;
	std::cout << "Starting Game" << std::endl << std::endl;
	caveSystem2.move();
	caveSystem2.move();
	caveSystem2.move();
}