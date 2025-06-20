#ifndef TERMINAL_H
#define TERMINAL_H

#include <string>
#include <iostream>

std::string takeBasePath();
void moveCursor(int arrowKey, std::string currentPath);
void deleteChar(std::string& charSequence, int currentPathSize);
void setConsoleTitle();

#endif
