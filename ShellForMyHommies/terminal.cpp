#include "terminal.h"
#include <iostream>
#include <Windows.h>
#include <strsafe.h>
#include <tchar.h>

// Returns the base path string for the shell prompt, e.g., "C:\Users\Username>"
std::string takeBasePath() {

    char* homeDrive = nullptr;
    char* homePath = nullptr;
    size_t homeDriveSize = 0;
    size_t homePathSize = 0;

    // Retrieve the HOMEDRIVE environment variable (e.g., "C:")
    _dupenv_s(&homeDrive, &homeDriveSize, "HOMEDRIVE");
    // Retrieve the HOMEPATH environment variable (e.g., "\Users\Username")
    _dupenv_s(&homePath, &homePathSize, "HOMEPATH");

    std::string basePath = (homeDrive ? homeDrive : "") + std::string(homePath ? homePath : "");

    std::wstring wBasePath = std::wstring(basePath.begin(), basePath.end());
    LPCTSTR path = wBasePath.c_str();
    SetCurrentDirectory(path); // Set the current process directory to basePath
    std::cout << "__cplusplus = " << __cplusplus << '\n';

    // Free memory allocated by _dupenv_s
    free(homeDrive);
    free(homePath);
    return basePath + ">";
}

// Moves the console cursor left or right based on arrow key input
void moveCursor(int arrowKey, std::string currentPath) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    COORD pos = csbi.dwCursorPosition;

    if (arrowKey == 75 && pos.X != currentPath.size()) {
        pos.X -= 1;
    }
    
    else if (arrowKey == 77) {
        pos.X += 1;
    }

    SetConsoleCursorPosition(hConsole, pos);
}

void deleteChar(std::string& charSequence, int currentPathSize) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    COORD pos = csbi.dwCursorPosition;

    // Calculate index in charSequence to delete, relative to prompt
    int indexToDelete = pos.X - currentPathSize - 1;
    // Ensure index is valid and within the input range
    if (indexToDelete >= 0 && pos.X <= currentPathSize + charSequence.size()) {

        // Remove character at the calculated index
        charSequence.erase(indexToDelete, 1);
        pos.X -= 1; // Move cursor left after deletion
        int cursorPos = pos.X;
        cursorVisibility(false);

        // Move cursor to start of input, overwrite with updated string and a space to clear leftover char
        pos.X = currentPathSize;
        SetConsoleCursorPosition(hConsole, pos);
        std::cout << charSequence << " ";

        // Restore cursor to correct position after deletion
        pos.X = cursorPos;
        SetConsoleCursorPosition(hConsole, pos);
        cursorVisibility(true);
    }
}

//  
void cursorVisibility(bool visible) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);

    if (visible) {
        cursorInfo.bVisible = TRUE;
    }
    else {
        cursorInfo.bVisible = FALSE;
    }
    
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}



void setConsoleTitle() {
    TCHAR szOldTitle[MAX_PATH];
    TCHAR szNewTitle[MAX_PATH];

    if (GetConsoleTitle(szOldTitle, MAX_PATH)) {
        StringCchPrintf(szNewTitle, MAX_PATH, TEXT("SHELL FOR MY HOMMIES: %s"), szOldTitle);
        SetConsoleTitle(szNewTitle);
    }
}