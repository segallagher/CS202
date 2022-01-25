

#include <iostream>
#include "MyClass.h"
#include <vector>

void printValue(MyClass data) {
	std::cout << data.ReadNum() << std::endl;
}

void setValue(MyClass& data,const int &value) {
	data.SetNum(value);
}

void passByConst(const MyClass& data) {
	std::cout << "Passed by Const" << std::endl;
}

MyClass createClass(const int& num) {
	return MyClass(num);
}

int main()
{
	MyClass guh(8);
	MyClass bruh = guh;
	std::cout << guh.ReadNum() << std::endl;
	std::cout << bruh.ReadNum() << std::endl;
	bruh.SetNum(-1);

	setValue(guh,3);
	printValue(guh);

	MyClass bean = createClass(7);

	MyClass zuh(2);
	MyClass chuh(21);
	MyClass huh(212);

	std::vector<MyClass> a = { guh,bruh,zuh,chuh,huh };
	
}