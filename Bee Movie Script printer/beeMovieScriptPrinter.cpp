#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include<chrono>
#include<thread>

using std::ifstream;
using std::vector;
using std::string;
using std::getline;

vector<string> returnScriptVector(const string fileName) {
	ifstream file(fileName);

	if (!file.is_open()) {
		vector<string> error{"-1"};
		return error;
	}
	
	string line;
	vector<string> script;

	while (getline(file, line)) {
		script.push_back(line);
	}
	return script;
}

void printScript(const vector<string>& script,const int & waitTime) {
	for (auto lines : script) {
		for (auto characters : lines) {
			std::cout << characters;
			std::this_thread::sleep_for(std::chrono::milliseconds(waitTime * 10));
		}
		std::cout << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(waitTime * 200));
	}
}



int main()
{
	vector<string> output = returnScriptVector("script.txt");
	printScript(output, 1);
}