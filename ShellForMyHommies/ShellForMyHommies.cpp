#include <iostream>
#include <stdlib.h>
#include <vector>
#include <conio.h>
#include <Windows.h>

std::string takeBasePath();

void moveCursorRight();

int main()
{

    std::string charSequence;
    std::string currentPath = takeBasePath();
    
    std::cout << currentPath;

	while (true) {
		
		int ch = _getch();
        char pressed_char = static_cast<char>(ch);

        // Remove the last character if Backspace is pressed
        if (ch == 8) {
            if (charSequence.size() > 0) {
                charSequence.pop_back();
                std::cout << "\b \b";
            }
        }

        // Arrow logic
        else if (ch == 0 || ch == 224) {
            int specialKey = _getch();

            if (static_cast<char>(specialKey) == 75) { // Left Arrow
                std::cout << "\b";
            }
            else if (static_cast<char>(specialKey) == 77){ // Right Arrow
                moveCursorRight();
            }
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

// Handle edge cases
void moveCursorRight() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    COORD pos = csbi.dwCursorPosition;
    pos.X += 1;  // move right by 1
    SetConsoleCursorPosition(hConsole, pos);
}


