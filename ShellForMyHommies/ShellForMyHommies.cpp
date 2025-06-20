#include "terminal.h"
#include <conio.h>

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