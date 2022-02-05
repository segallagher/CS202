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
	std::chrono::microseconds readMicroseconds();
	std::chrono::nanoseconds readNanoseconds();
	int readSystemTime();

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> _startTime;
	std::chrono::time_point<std::chrono::high_resolution_clock> _stopTime;

};

#endif
