#pragma once
#ifndef STOPWATCH_CPP
#define STOPWATCH_CPP

#include <chrono>

class Stopwatch {
public:
	Stopwatch();
	void start();
	void stop();
	double readSeconds();
	std::chrono::milliseconds readMilliseconds();
	std::chrono::nanoseconds readNanoseconds();

private:
	std::chrono::time_point<std::chrono::system_clock> _startTime;
	std::chrono::time_point<std::chrono::system_clock> _stopTime;

};

#endif
