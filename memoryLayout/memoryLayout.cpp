#include <iostream>

static int glob = 100;
static int glob1 = 101;
static int glob2 = 102;
static int glob3 = 150;
static int glob4 = 99;

void printPointer(int & i) {
    int* iptr = &i;
    int mIntAddress = (int)&i/sizeof(int); //memory location of integer variable in the form of an integer
    std::cout << "i = " << *iptr << "\n";
    //std::cout << "&i = " << iptr << "\n";
    std::cout << "&i = " << mIntAddress << "\n";
}

void f3() {
    int i = 60;
    printPointer(i);
    return;
}

void f2() {
    int i = 60;
    printPointer(i);
    f3();
}

void f1() {
    int i = 60;
    printPointer(i);
    f2();
}

int main()
{
    std::cout << "\nArray addresses\n" << std::endl;
    int joe[] = { 2,5,6,7 };
    for (int i = 0; i < 4; i++) {
        printPointer(joe[i]);
        std::cout << "-----------------" << std::endl;
    }
    std::cout << "\nFunction calls\n" << std::endl;
    f1();
    std::cout << "Global Variables (ie: static data)\n" << std::endl;
    printPointer(glob);
    printPointer(glob1);
    printPointer(glob2);
    printPointer(glob3);
    printPointer(glob4);
    std::cout << "\nHeap Data\n" << std::endl;
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 10;
    printPointer(*ptr);
    free(ptr);
}