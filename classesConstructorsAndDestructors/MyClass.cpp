#include "MyClass.h"

MyClass::MyClass() {

}

MyClass::MyClass(const MyClass& g) {

}

MyClass::MyClass(const int& h) {

}

void MyClass::SetNum(const int &num) {
	_num = num;
}

int MyClass::ReadNum() {
	return _num;
}