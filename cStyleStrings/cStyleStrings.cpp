// cStyleStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

char* Mystrdup(const char* d) {
    char* ego = new char [strlen(d)+1];

    return ego;
}

char* findx(const char* s, const char* x) {

}

int main()
{
    const char *da= "Goobla";
    std::cout << *Mystrdup(da) << std::endl;
}
