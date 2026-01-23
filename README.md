![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=cplusplus&logoColor=white) 
![C++11](https://img.shields.io/badge/C++11-100%25-00599C?style=flat&logo=cplusplus&logoColor=white) 
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)

# 🔧 cpp-starter

Welcome to **cpp-starter**, a repository dedicated to documenting my C++ studies using *C++ Primer* (5th Edition, Lippman, Lajoie & Moo). This repository contains solved exercises, practical projects, and notes about the language and its concepts — organized for clarity and reuse.

---

## 📁 Repository structure

The repository is organized by book chapters and projects. Each exercise or relevant file lives in its own directory to keep the repository navigable.

```text
├── chapters/
│   ├── ch01/
│   │   ├── ch01-ex1_hello.cpp
│   │   └── ch01-ex2_io.cpp
│   ├── ch02/
│   │   ├── ch02-ex1_types.cpp
│   │   └── ch02-ex2_variables.cpp
├── projects/
│   ├── text-processor/
│   ├── simple-game/
│   └── system-monitor/
└── README.md
```

---

## ▶️ How to run the code

You can compile and run the exercise files or small scripts with a C++ compiler. Replace `path/to/source.cpp` with the actual file path.

### On Windows (using Visual Studio Build Tools):

First, install **Visual Studio Build Tools** to get access to **MSVC** and **Clang**:
- Download from: https://visualstudio.microsoft.com/downloads/
- Select "Desktop development with C++" workload during installation

Open **Developer Command Prompt** or **Developer PowerShell** and run:

```powershell
# Using MSVC
cl /EHsc /std:c++11 path\to\source.cpp
.\source.exe

# Using Clang (if installed via Build Tools)
clang++ -std=c++11 path\to\source.cpp -o source.exe
.\source.exe
```

### On Linux / macOS:

Install **GCC** or **Clang**:

```bash
# Debian/Ubuntu
sudo apt install g++ clang

# Fedora
sudo dnf install gcc-c++ clang

# Arch
sudo pacman -S gcc clang

# macOS (Xcode Command Line Tools)
xcode-select --install
```

Compile and run:

```bash
# Using GCC
g++ -std=c++11 -O2 path/to/source.cpp -o program
./program

# Using Clang
clang++ -std=c++11 -O2 path/to/source.cpp -o program
./program
```

### Multiple source files:

```bash
# GCC
g++ -std=c++11 -O2 src/main.cpp src/utils.cpp -Iinclude -o program

# Clang
clang++ -std=c++11 -O2 src/main.cpp src/utils.cpp -Iinclude -o program

# MSVC
cl /EHsc /std:c++11 /Iinclude src\main.cpp src\utils.cpp
```

---

## 🎯 Objectives

- Document my study progress through *C++ Primer* (5th Edition)
- Solve the book exercises with well-commented code
- Build practical projects that apply the learned concepts
- Share solutions and insights with the community
- Establish a solid base of knowledge in modern C++

---

## 🌍 Why C++?

C++ offers raw power for building abstractions while maintaining the ability to program using low-level operating system APIs. It bridges high-level design with system-level control, enabling:

- Direct access to system resources and hardware
- Programming with low-level APIs like *POSIX**, **Win32**, **DirectX**, and more
- Building high-performance applications, game engines, and system software
- Creating powerful abstractions without sacrificing efficiency
- Fine-grained control over memory management and resource allocation
- Cross-platform development from embedded systems to desktop applications

*C++ Primer* (5th Edition) stands out because it teaches modern C++ practices, emphasizing both language fundamentals and the standard library, preparing you for real-world software development.

---

## 🛠️ Development environment

Compilers:
- **Windows**: MSVC (Visual Studio Build Tools) or Clang
- **Linux**: GCC or Clang
- **macOS**: Clang (Xcode Command Line Tools) or GCC (via Homebrew)

Standard:
- C++11

Tools:
- Visual Studio Code with C/C++ extension
- GDB or LLDB for debugging

---

## 📚 Useful resources

- C++ Primer (5th Edition) — Lippman, Lajoie & Moo
- cppreference.com — Comprehensive C++ reference: https://en.cppreference.com/
- C++ Core Guidelines: https://isocpp.github.io/CppCoreGuidelines/
- LearnCpp.com — Modern C++ tutorial: https://www.learncpp.com/
- Microsoft C++ Documentation: https://docs.microsoft.com/en-us/cpp/
- GCC Documentation: https://gcc.gnu.org/onlinedocs/
- Clang Documentation: https://clang.llvm.org/docs/

---

## 🤝 Contributions

This repository is primarily a personal study log, but constructive contributions are welcome:

- Open issues for questions, suggestions, or corrections
- Propose alternative solutions for exercises
- Suggest improvements for structure or documentation

Please keep discussions focused and respect the project license.

---

## 🌐 Contact

For questions, feedback, or discussions about C++ and learning approaches, visit:
https://github.com/snake-outerheaven

---

## 📄 License

This project is licensed under the MIT License.

You are free to:
- Use the code for any purpose
- Study and modify the code
- Share the original code and your modifications

See the `LICENSE` file for full details.

---

Made with focus, discipline, and deliberate practice — snake-outerheaven

---
