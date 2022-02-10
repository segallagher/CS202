#include <iostream>
#include <list>

struct Something
{
    Something();
    void queue();
    void stack();
    void insertion();
    bool search();
    ~Something();
private:
    std::list<int> vList;
};

int main()
{
    std::cout << "Hello World!\n";
}
