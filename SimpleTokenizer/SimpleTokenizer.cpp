#include <iostream>
using std::cout;
using std::endl;
#include "Word.h"
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
using std::ofstream;

vector<Word> createWordData(string & fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error reading file " << fileName << endl;
        return vector<Word>{};
    }
    vector<Word> words;
    string line;
    while (std::getline(file, line)) {
        for (auto n : line) {
            /////////////////////////////
        }
    }
}

int main()
{
    std::cout << "Hello World!\n";
}
