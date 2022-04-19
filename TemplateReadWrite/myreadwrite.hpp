#pragma once

#include <fstream>
#include <vector>
#include <string>

void myRead(std::ifstream& ifile,int &readT) {
	ifile.read(reinterpret_cast<char*>(&readT),sizeof(readT));
}

void myWrite(std::ostream& ofile,const int &writeT) {
	ofile.write(reinterpret_cast<const char*>(&writeT), sizeof(writeT));
}
