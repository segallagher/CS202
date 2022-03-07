#include <iostream>
using std::cout;
using std::endl;
#include "Word.h"
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include<sstream>
using std::istream;

vector<string> lineToTokens(const string& line) {
    vector<string> tokens;
    std::stringstream g(line);
    string token;
    while(std::getline(g, token,' ')) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<Word> readLines(istream& is) {

}

void printTokens(ostream& os, const vector<Word>& tokens) {
    for (auto n : tokens) {
        os << n << endl;
    }
}

vector<Word> createWordData(const string & fileName) {
    char delim = ' ';

    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error reading file " << fileName << endl;
        return vector<Word>{};
    }
    vector<Word> words;
    string line;
    int lineNum = 0;
    while (std::getline(file, line)) {
        lineNum++;
        bool reading = false;
        string tmp;
        int columnNum;
        for (int i = 0; i < line.size();i++) {
            if (line.at(i) != delim) {
                reading = true;
                if (i == 0 || line.at(i - 1) == delim ) {
                    columnNum = i;
                }
            }
            else {
                reading = false;
                words.push_back(Word(tmp, lineNum, columnNum + 1));
                tmp.erase();
            }
            if (reading) {
                tmp.push_back(line[i]);
            }
        }
    }
    return words;
}

void printWords(vector<Word> & data) {
    for (auto n : data) {
        cout << n << endl;
    }
}

int main(int argc, char *argv[])
{
    cout << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }
    //vector<Word> wordList = createWordData("book.txt");
    //printWords(wordList);
    std::cout << "done" << std::endl;
}
