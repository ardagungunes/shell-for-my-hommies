#include <iostream>
#include <stdlib.h>
#include <vector>
#include <conio.h>
#include <Windows.h>

std::string takeBasePath();

void moveCursor(int, std::string);

void deleteChar(std::string&, int);


int main()
{
   
    std::string currentPath = takeBasePath();
    std::string charSequence;
     
    std::cout << currentPath;

	while (true) {
		
		int ch = _getch();
        char pressed_char = static_cast<char>(ch);


        // Remove the last character if Backspace is pressed
        if (ch == 8) {
            if (charSequence.size() > 0 ) {
                deleteChar(charSequence, currentPath.size());
            }
        }

        // Arrow logic
        else if (ch == 0 || ch == 224) {
            int specialKey = _getch();

            moveCursor(specialKey, currentPath);
        }

        // Printable characters
        else if (ch >= 32 && ch <= 126) {
            charSequence += pressed_char;
            std::cout << pressed_char;
        }
        
		
        // Exit the loop if Esc is pressed (Debugging only)
        if (ch == 27) 
        {
            std::cout << "\n[ESC] Exit triggered.\n";
            break;
        }
            

	}

    std::cout << "\nCaptured Sequence: " << charSequence << std::endl;
    

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

// Handle edge cases!
void moveCursor(int arrowKey, std::string currentPath) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    COORD pos = csbi.dwCursorPosition;
    if (arrowKey == 75 && pos.X != currentPath.size()) {
        pos.X -= 1;  // move left by 1
    }
    else if(arrowKey == 77){
        pos.X += 1;  // move right by 1
    }
    
    SetConsoleCursorPosition(hConsole, pos);
}

// There is a bug!!! Try shifting the chars or if there is, find more optimal solutions
void deleteChar(std::string& charSequence, int currentPathSize) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    COORD pos = csbi.dwCursorPosition;

    int charSequenceSize = charSequence.size();
    int indexToDelete = pos.X - currentPathSize - 1;
    
    if (indexToDelete >= 0 && pos.X <= charSequenceSize + currentPathSize) {
        charSequence.erase(indexToDelete, 1);
        std::cout << "\b \b";
    }

}


