#include "Stopwatch.h"

Stopwatch::Stopwatch() {

}

void Stopwatch::start() {
	_startTime = std::chrono::system_clock::now();
}

void Stopwatch::stop() {
	_stopTime = std::chrono::system_clock::now();
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