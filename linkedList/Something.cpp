#include "Something.h"

Something::Something() {
	_vList = {};
}

Something::Something(std::list<int>& list) {
	_vList = list;
}

void Something::queue(const int& num) {
	_vList.pop_front();
	_vList.push_back(num);
}

void Something::stack(const int& num) {
	_vList.pop_back();
	_vList.push_back(num);
}

void Something::sort() {
	_vList.sort();
}

void Something::insertion(const int& num) {
	std::list<int> newList;
	std::list<int>::iterator it = _vList.begin();
	int k;
	for (int i = 0; i < _vList.size(); i++) {
		if (*it > num) {
			newList.push_back(num);
			k = i;
			break;
		}
		newList.push_back(*it);
		it++;
	}
	for (int i = k; i < _vList.size(); i++) {
		newList.push_back(*it);
		it++;
	}
	_vList = newList;
}

bool Something::search(const int& num) {
	_vList.push_back(num);
	_vList.pop_front();
}
