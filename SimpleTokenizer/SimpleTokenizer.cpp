#include <iostream>
using std::cout;
using std::endl;
#include "Word.h"
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <sstream>
using std::istream;
#include <algorithm>

#if 0
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
    std::ostringstream sstr;
    sstr << is.rdbuf();
    vector<Word> words;
    string line = sstr.str();
    //while (std::getline(is, line, ' ')) {
        vector<string> tokens = lineToTokens(line);
        for (auto n : tokens) {
            cout << sstr.str().find(n) << endl;
        }
        //line
     //   std::for_each(tokens.begin(), tokens.end(),[] words.push_back(Word("d",1,1)));
        
    //}
}

void printTokens(ostream& os, const vector<Word>& tokens) {
    for (auto n : tokens) {
        os << n << endl;
    }
}
#endif
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
    if (argc == 1) {
        vector<Word> wordList = createWordData(argv[1]);
        printWords(wordList);
    }
    vector<Word> wordList = createWordData("book.txt");
    printWords(wordList);
    std::cout << "done" << std::endl;
}
