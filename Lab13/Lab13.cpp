#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;



template<typename T>
T twice(const T & input) {
	return input + input;
}

int main()
{
	cout << twice(2) << endl;
	cout << twice(2.3) << endl;
	cout << twice(string("Hello")) << endl;
}