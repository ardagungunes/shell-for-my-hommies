#include "parser.h"
#include "utils.h"
#include "commands.h"
#include <iostream>
#include <vector>
#include <filesystem>


std::vector<std::string> tokenize(std::string str) {
	std::vector<std::string> vec;
	std::string splittedString;

	for (char ch : str) {

		splittedString += ch;

		if (ch == ' ' || ch == ';') {

			splittedString.pop_back();

			vec.push_back(splittedString);

			if (ch == ';') {
				vec.push_back(";");
			}

			splittedString.clear();
		}

		

	}

	vec.push_back(splittedString);

	return vec;
}

parseTree parser(std::vector<std::string> tokens) {

	parseTree parseTree;

	for (std::string token : tokens) {
		trimCommands(token);

		if (token == "cd" || token == "ls") {
            
			parseTree.parsings.push_back(parserStruct{});
			parseTree.parsings.back().command = token;
		}

		else if (isPathValid(token)) {
			parseTree.parsings.back().path = token;
		}

		else if (token == ";") {
			parseTree.parsings.push_back(parserStruct{});
		}

	}

	return parseTree;
}




