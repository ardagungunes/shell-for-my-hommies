#include "utils.h"
#include <iostream>
#include <vector>

std::vector<std::string> splitString(std::string str, char splitToken) {
	std::vector<std::string> vec;
	std::string splittedString;

	for (char ch : str) {

		splittedString += ch;

		if (ch == splitToken) {
			vec.push_back(splittedString);
			splittedString.clear();
		}

	}

	vec.push_back(splittedString);

	return vec;
}