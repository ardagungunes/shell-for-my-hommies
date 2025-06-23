#include "terminal.h"
#include "commands.h"
#include <Windows.h>
#include <filesystem>



const std::string SHELL_CD = "cd ";

// cd
void changeDirectory() {
	std::cout << std::endl << "cd command is working...";
}

bool isPathValid(std::string& path) {
	return std::filesystem::exists(path) && std::filesystem::is_directory(path);
}