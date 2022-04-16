#include <iostream>
#include "Wrapper.hpp"
#include <string>
using std::string;
using std::cout;
using std::endl;


int main()
{
	Wrapper<int> w{ 2 };
	Wrapper<string>  s{ "Hello world!" };
	cout << w << " " << s << endl;
}