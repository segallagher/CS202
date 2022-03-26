#pragma once

#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP
#include <vector>
#include <string>

std::vector<std::string> Tokenize(const std::string & input,const char & delim) {
	std::vector<std::string> output;
	std::string str;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] != delim) {
			str.push_back(input[i]);
		}
		else {
			output.push_back(str);
			str = "";
		}
	}

	return output;
}


#endif
