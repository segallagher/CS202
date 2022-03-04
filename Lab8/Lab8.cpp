#include <iostream>
#include "Swarm.h"

int Swarm::objectCount = 0;

void staticTest() {
    static int x = 6;
    x++;
    std::cout << x << std::endl;
}


int main()
{
    staticTest();
    staticTest();
    staticTest();
    staticTest();

    Swarm joe = Swarm();
    Swarm b = Swarm();
    Swarm c = Swarm();
    Swarm d = Swarm();

    //joe.add(4);
    std::cout << "Swarm Count: " << Swarm::objectCount << std::endl;
}