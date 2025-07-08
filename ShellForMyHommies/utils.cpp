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

void trimCommands(std::string& command) {
	command.erase(0, command.find_first_not_of(" \t"));
	command.erase(command.find_last_not_of(" \t") + 1);
}