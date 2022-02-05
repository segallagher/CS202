#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "Stopwatch.h"
#include <random>
#include <algorithm>
#include <deque>
using std::vector;
using std::string;
using std::ifstream;
using std::getline;

vector<string> returnScriptVector(const string fileName) {
	ifstream file(fileName);

	if (!file.is_open()) {
		vector<string> error{ "Error opening " + fileName };
		return error;
	}

	string line;
	vector<string> script;

	while (file >> line) {
		script.push_back(line);
	}
	return script;
}

std::deque<string> returnScriptDeque(const string fileName) {
	ifstream file(fileName);

	if (!file.is_open()) {
		std::deque<string> error{ "Error opening " + fileName };
		return error;
	}

	string line;
	std::deque<string> script;

	while (file >> line) {
		script.push_back(line);
	}
	return script;
}

#if 0
//This code works but not in this function
std::list<string> listTime(string& fileName) {
	std::ifstream file(fileName);
	std::string dum;
	std::list<string> listBook;
	while (file >> dum) {
		listBook.push_back(dum);
	}
}
#endif

int main()
{
	for (int i = 1; i < 6; i++) {
		string fileName = std::to_string(i) + ".txt";
		
		std::ifstream file(fileName);
		std::string dum;
		std::list<string> listBook;
		while (file >> dum) {
			listBook.push_back(dum);
		}

		vector<string> vectorScript = returnScriptVector(fileName);

		int size = vectorScript.size();
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(1, size);
		string target = vectorScript[dist(gen)];
		std::cout << "Target: " << target << std::endl;

		Stopwatch listTimer;
		listTimer.start();
		std::list<string>::iterator it1 = std::find(listBook.begin(), listBook.end(), target);
		listTimer.stop();
		string a = *it1;//must be here otherwise the proccess takes 0 time

		Stopwatch vecTimer;
		vecTimer.start();
		std::vector<string>::iterator it2 = std::find(vectorScript.begin(), vectorScript.end(), target);
		vecTimer.stop();
		string b = *it2;//must be here otherwise the proccess takes 0 time

		std::deque<string> de = returnScriptDeque(fileName);

		Stopwatch dequeTimer;
		dequeTimer.start();
		std::deque<string>::iterator it3 = std::find(de.begin(), de.end(), target);
		dequeTimer.stop();
		string c = *it3;//must be here otherwise the proccess takes 0 time
		
		std::cout << "List Search Time(ns):   " << listTimer.readNanoseconds().count() << std::endl;
		std::cout << "Vector Search Time(ns): " << vecTimer.readNanoseconds().count() << std::endl;
		std::cout << "Deque Search Time(ns):  " << dequeTimer.readNanoseconds().count() << std::endl;
		std::cout << std::endl;
	}

}

