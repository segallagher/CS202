#include <iostream>

void printPointer(int i) {
    int* iptr = &i;
    std::cout << "i = " << *iptr << "\n";
    std::cout << "&i = " << iptr << "\n";
}

int main()
{
    std::cout << "Hello World!\n";
}