#include "Swarm.h"

static int objectCount;

Swarm::Swarm() { num = 5; objectCount++; }

void Swarm::add(const int& value) { num += value; };