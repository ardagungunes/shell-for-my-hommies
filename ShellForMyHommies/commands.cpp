#include "terminal.h"
#include "commands.h"
#include "utils.h"
#include <Windows.h>
#include <filesystem>


const std::string SHELL_CD = "cd ";
const std::string SHELL_LS = "ls";

// cd
void changeDirectory(std::string& charSequence, std::string& currentPath, std::string basePath) {

	std::string targetDirectory = charSequence.substr(3);
	trimCommands(targetDirectory);
	
	//std::cout << " Target Directory: " << "[" << targetDirectory << "]";

	if (targetDirectory == "..") {
		
		std::string currentPathCopy = currentPath;
		currentPathCopy.pop_back();
		std::string path = previousPath(splitString(currentPathCopy, '\\'), basePath);

		if (!path.empty()) {
			currentPath.pop_back();
			currentPath = path;
			changeProcessDirectory(currentPath);
			currentPath += ">";
		}
	}

	else if (isPathValid(targetDirectory)) {
		currentPath.pop_back();
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



void changeProcessDirectory(std::string& currentPath) {
	std::wstring wBasePath = std::wstring(currentPath.begin(), currentPath.end());
	LPCTSTR path = wBasePath.c_str();
	SetCurrentDirectory(path);
}

// ls
void listFiles(std::string currentPath) {

	currentPath = currentPath.erase(currentPath.size() - 1);
	std::cout << std::endl;
    
        for (auto const& dir_entry : std::filesystem::directory_iterator{currentPath})
            std::cout << dir_entry.path().filename() << '\n';
     
}

std::string previousPath(std::vector<std::string> paths, std::string basePath) {

	std::string newPath;

	if (!paths.empty()) {
		paths.pop_back();
	}

	for (std::string path: paths) {
		newPath += path;
	}
	
	if (newPath.size() >= basePath.size()) {
		newPath.pop_back();
		return newPath;
	}

	return "";
}