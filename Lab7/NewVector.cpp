#include "NewVector.h"

NewVector::NewVector() {
	_vec = vector<int>{};
}

NewVector::NewVector(const vector<int>& vec) {
	_vec = vec;
}

void NewVector::append(const int& num) {
	_vec.push_back(num);
}