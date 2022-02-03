// cStyleStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

const char* Mystrdup(const char* d) {
    std::string str = d;
    const char* m = str.c_str();
    return m;
}

char* findx(const char* s, const char* x) {

}

int main()
{
    const char *da= "Goobla";
    std::cout << da << std::endl;
    const char* ee = Mystrdup(da);
    std::cout << ee[0] << std::endl;
}
