#include "Stopwatch.h"

Stopwatch::Stopwatch() {

}

void Stopwatch::start() {
	_startTime = std::chrono::high_resolution_clock::now();
}

void Stopwatch::stop() {
	_stopTime = std::chrono::high_resolution_clock::now();
}

double Stopwatch::readSeconds() {
	return std::chrono::duration_cast<std::chrono::milliseconds> (_stopTime - _startTime).count()/1000.0;
}

std::chrono::milliseconds Stopwatch::readMilliseconds() {
	return std::chrono::duration_cast<std::chrono::milliseconds> (_stopTime - _startTime);
}

std::chrono::nanoseconds Stopwatch::readNanoseconds() {
	return std::chrono::duration_cast<std::chrono::nanoseconds> (_stopTime - _startTime);
}

std::chrono::microseconds Stopwatch::readMicroseconds() {
	return std::chrono::duration_cast<std::chrono::microseconds> (_stopTime - _startTime);
}

int Stopwatch::readSystemTime() {
	return (_stopTime - _startTime).count();
}