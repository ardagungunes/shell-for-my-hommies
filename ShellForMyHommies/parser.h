#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>

struct parserStruct {
	std::string command;
	std::string path;
	std::string commandSeperator;
};

struct parseTree
{
	std::vector<parserStruct> parsings;
};



std::vector<std::string> tokenize(std::string str);
parseTree parser(std::vector<std::string> tokens);


#endif
