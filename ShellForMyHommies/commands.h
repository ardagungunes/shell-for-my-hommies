#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>

extern const std::string SHELL_CD;
extern const std::string SHELL_LS;

void changeDirectory(std::string&, std::string&);
void trimCommands(std::string&);
void changeProcessDirectory(std::string&);
bool isPathValid(std::string& path);
void listFiles(std::string currentPath);

#endif

