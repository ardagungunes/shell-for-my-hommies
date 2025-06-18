#include <iostream>
#include <stdlib.h>
#include <vector>

std::string takeBasePath();

int main()
{

    std::vector<int> charVector;
    std::string currentPath = takeBasePath();
    
    std::cout << currentPath;

	while (true) {
		
		int ch = std::cin.get();
        charVector.push_back(ch);
		
        
	}

    return 0;
}

std::string takeBasePath() {

    char* homeDrive = nullptr;
    char* homePath = nullptr;
    size_t homeDriveSize = 0;
    size_t homePathSize = 0;
    

    _dupenv_s(&homeDrive, &homeDriveSize, "HOMEDRIVE");
    _dupenv_s(&homePath, &homePathSize, "HOMEPATH");
  

    std::string basePath;
    basePath = (homeDrive ? homeDrive : "") + std::string(homePath ? homePath : "") + std::string(">");
    

    // Must free the allocated memory
    free(homeDrive);
    free(homePath);

    
    return basePath;
}


