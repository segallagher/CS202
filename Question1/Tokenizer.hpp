#pragma once

#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP
#include <vector>
#include <string>

std::vector<std::string> Tokenize(const std::string & input,const char & delim) {
	std::vector<std::string> output;
	std::string str;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == delim || i == input.size()-1) {	// check if delim or end of string
			if(i == input.size()-1){ str.push_back(input[i]); }	// add character at end of word
			output.push_back(str);
			str = "";
		}
		else {
			str.push_back(input[i]);
		}
	}

	return output;
}


#endif
