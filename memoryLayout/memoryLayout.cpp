#include <iostream>

static int glob = 100;

void printPointer(int & i) {
    int* iptr = &i;
    int mIntAddress = (int)&i/sizeof(int); //memory location of integer variable in the form of an integer
    std::cout << "i = " << *iptr << "\n";
    //std::cout << "&i = " << iptr << "\n";
    std::cout << "&i = " << mIntAddress << "\n";
}

int main()
{
    printPointer(glob);
    std::cout << "Array addresses" << std::endl;
    int joe[] = { 2,5,6,7 };
    for (int i = 0; i < 4; i++) {
        printPointer(joe[i]);
        std::cout << "-----------------" << std::endl;
    }
}