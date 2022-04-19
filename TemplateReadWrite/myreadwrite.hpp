#pragma once
#ifndef MYREADWRITE_HPP
#define MYREADWRITE_HPP


#include <fstream>
#include <vector>
#include <string>

template<typename T>
void myRead(std::ifstream& ifile,T &readT) {
	ifile.read(reinterpret_cast<char*>(&readT),sizeof(readT));
}

template<typename T>
void myWrite(std::ostream& ofile,const T &writeT) {
	ofile.write(reinterpret_cast<const char*>(&writeT), sizeof(writeT));
}

#endif