#include "MyClass.h"

MyClass::MyClass() {
	_num = 0;
}

MyClass::MyClass(const MyClass& g) {
	_num = g._num;
}

MyClass::MyClass(const int& h) {
	_num = h;
}

void MyClass::SetNum(const int &num) {
	_num = num;
}

int MyClass::ReadNum() {
	return _num;
}