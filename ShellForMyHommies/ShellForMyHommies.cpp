#include "terminal.h"
#include "commands.h"
#include <conio.h>

bool startsWith(std::string&, const std::string&);

int main() {

    std::string currentPath = takeBasePath();
    std::string charSequence;

    setConsoleTitle();
    std::cout << currentPath;

    while (true) {

        int ch = _getch();
        char pressed_char = static_cast<char>(ch);

        if (ch == 8) {
            if (!charSequence.empty()) {
                deleteChar(charSequence, currentPath.size());
            }
        }
        else if (ch == 0 || ch == 224) {
            int specialKey = _getch();
            moveCursor(specialKey, currentPath);
        }
        else if (ch >= 32 && ch <= 126) {
            charSequence += pressed_char;
            std::cout << pressed_char;
        }
        else if (ch == 13) {
            if (startsWith(charSequence, SHELL_CD)) {
                changeDirectory(charSequence, currentPath);
            }
            else {
                std::cout << "Unrecognized command!" << std::endl;
            }
            std::cout << std::endl << currentPath;
        }

        // Debugging Only!!!
        if (ch == 27) {
            std::cout << "\n[ESC] Exit triggered.\n";
            break;
        }
    }

    // Debugging Only
    std::cout << "\nCaptured Sequence: " << charSequence << std::endl;
    return 0;
}

bool startsWith(std::string& str, const std::string& cmp) {
    return str.compare(0, cmp.length(), cmp) == 0;
}