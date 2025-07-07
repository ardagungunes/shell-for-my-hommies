# ShellForMyHomies

A fun, minimal Windows-based shell written in C++ for learning purposes. This project was developed to better understand how terminals work, explore the Windows API, and get hands-on experience with C++17/20 features like `std::filesystem`. It includes basic command parsing, cursor control, custom prompt handling, and initial shell commands like `cd` and `ls`.

---

## 🚀 Features

- 🖥️ Custom shell prompt showing current directory
- ⌨️ Real-time character capturing with `_getch()`
- ⬅️ Cursor movement using arrow keys
- 🔙 Backspace support with visual character deletion
- 📁 `cd` command (including `cd ..`)
- 📂 `ls` command to list current directory contents
- 🎯 Uses WinAPI and `std::filesystem` for directory manipulation
- 🧹 Trim utilities for whitespace handling

---

## 🧠 Learning Objectives

This project was designed to:

- Explore Windows API (console buffer manipulation, cursor visibility, setting console title)
- Practice manual input handling
- Understand string manipulation and parsing in C++
- Set up modular C++ projects using headers and source files
- Prepare for more complex systems like OpenGL projects or full-featured shells

---

## 🔧 Build Instructions

### 🛠 Requirements

- **Windows OS**
- **Visual Studio 2022** (or compatible C++ compiler with C++17+ support)
- C++17 or C++20

### ✅ How to build

1. Open the project folder in Visual Studio
2. Ensure language standard is set to C++17 or higher (Project > Properties > C/C++ > Language > C++ Language Standard)
3. (Optional) Add `/Zc:__cplusplus` to correctly set `__cplusplus` macro
4. Build & run

---

## 📂 File Structure

```
ShellForMyHomies/
├── ShellForMyHomies.cpp     # Main loop and input handling
├── terminal.h / terminal.cpp    # Console manipulation (cursor, deletion, title)
├── commands.h / commands.cpp    # Shell commands: cd, ls, validation
├── utils.h / utils.cpp          # Helper functions (e.g., splitString, trim)
```

---

## 💡 Sample Commands

```bash
cd myFolder
cd ..
ls
```

Unrecognized commands will print:

```
Unrecognized command!
```

---

## 🛠️ Planned / Future Features

- `mkdir`, `touch`, and `open` support
- Basic tokenizer/parser for handling multiple piped commands
- Syntax highlighting in console output
- Launch mini-games (OpenGL-based) from shell interface
- Support for command history and arrow-key navigation

---

## 📘 Notes

- This is a personal learning project and not intended as a production shell
- Designed with modularity in mind: you can extend commands easily
- `std::filesystem` requires C++17+, so make sure your project is configured accordingly

---

## 📝 License

This project is released under the MIT License.

