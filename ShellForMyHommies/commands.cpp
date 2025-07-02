#include "terminal.h"
#include "commands.h"
#include <Windows.h>
#include <filesystem>



const std::string SHELL_CD = "cd ";

// cd
void changeDirectory(std::string& charSequence, std::string& currentPath) {

	std::string targetDirectory = charSequence.substr(3);
	trimCommands(targetDirectory);

	if (isPathValid(targetDirectory)) {
		currentPath.erase(currentPath.size() - 1);
		currentPath += ("\\" + targetDirectory);
		changeProcessDirectory(currentPath);
		currentPath += ">";
	}
	else {
		std::cout <<std::endl<< "The path: " << "'" << targetDirectory << "'" << " is not recognized!" << std::endl;
	}
	
}

bool isPathValid(std::string& path) {
	return std::filesystem::exists(path) && std::filesystem::is_directory(path);
}

void trimCommands(std::string& command) {
	command.erase(0, command.find_first_not_of(" \t"));
	command.erase(command.find_last_not_of(" \t") + 1);
}

void changeProcessDirectory(std::string& currentPath) {
	std::wstring wBasePath = std::wstring(currentPath.begin(), currentPath.end());
	LPCTSTR path = wBasePath.c_str();
	SetCurrentDirectory(path);
}