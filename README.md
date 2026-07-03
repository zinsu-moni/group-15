# Wage Calculator

A professional console-based wage calculator application written in modern C++.

## Table of Contents
- [Features](#features)
- [System Requirements](#system-requirements)
- [Project Structure](#project-structure)
- [Setup & Compilation](#setup--compilation)
  - [macOS / Linux](#macos--linux)
  - [Windows](#windows)
- [How to Use](#how-to-use)
  - [macOS / Linux](#macos--linux-1)
  - [Windows](#windows-1)
- [Troubleshooting](#troubleshooting)
- [Classes](#classes)
- [Documentation](#documentation)
- [Lecturer Preparation](#lecturer-preparation)

## Features
- Object-oriented design
- Robust input validation (prevents invalid numbers, negative values, empty inputs, and extremely large values)
- Calculates regular pay, overtime pay (1.5x hourly rate for >40hrs), gross pay, 5% tax, and net pay
- Generates a formatted, professional payslip
- Follows C++ best practices (const-correctness, RAII, no manual memory management)
- Cross-platform support (macOS, Linux, and Windows)

## System Requirements
- A C++17-compatible compiler:
  - macOS: Clang (pre-installed) or GCC
  - Linux: GCC or Clang
  - Windows: MSVC (Visual Studio), MinGW, or Clang
- A terminal/command prompt to run the program
- Optional build tools:
  - Make (for Makefile method)
  - CMake (for cross-platform build generation)

## Project Structure
```
group 15/
├── CMakeLists.txt         # CMake build configuration (cross-platform)
├── Makefile               # Make build configuration (for macOS/Linux)
├── README.md              # This file! Project documentation
├── LECTURER_QUESTIONS.md  # Q&A for lecturer preparation
├── .gitignore             # Git ignore rules for build files
├── main.cpp               # Application entry point
├── Employee.h/cpp         # Employee class (stores employee data)
├── InputHandler.h/cpp     # User input handling and validation workflow
├── InputValidator.h/cpp   # Input validation logic (ranges, non-negative values, etc.)
├── Payslip.h/cpp          # Payslip data and professional display
├── WageCalculator.h/cpp   # Wage calculation business logic
└── Utils.h/cpp            # Utility functions (placeholder for future use)
```

## Setup & Compilation

### macOS / Linux

#### Method 1: Using Make (Recommended)
1. Open your terminal
2. Navigate to the project directory:
   ```bash
   cd "/Users/apple/Desktop/group 15"
   ```
3. Clean any previous build files and compile the program:
   ```bash
   make clean && make
   ```
4. You should see the `WageCalculator` executable file appear in the project directory

#### Method 2: Using CMake (Alternative)
If you prefer CMake:
1. Open your terminal
2. Navigate to the project directory:
   ```bash
   cd "/Users/apple/Desktop/group 15"
   ```
3. Create a build directory, navigate into it, generate build files, and compile:
   ```bash
   mkdir -p build && cd build
   cmake .. && make
   ```
4. The executable will be in the `build` directory (run it with `./WageCalculator`)

---

### Windows

#### Method 1: Using Visual Studio (MSVC)
1. Install [Visual Studio Community](https://visualstudio.microsoft.com/vs/community/) (free)
2. Make sure to select **"Desktop development with C++"** during installation
3. Open Visual Studio
4. Select **"File" > "Open" > "Folder"** and select the `group 15` project folder
5. Or, create a new C++ Console Project and copy-paste all the .h and .cpp files into it
6. Right-click `main.cpp` in the Solution Explorer and select **"Set as Startup Item"**
7. Press `Ctrl+Shift+B` to build the project, or click **"Build" > "Build Solution"**
8. The executable will be in the `x64/Debug` or `x64/Release` folder of your project

#### Method 2: Using MinGW (Minimalist GNU for Windows)
1. Install MinGW-w64 (recommended) via [MSYS2](https://www.msys2.org/) or download a pre-built version
2. Add MinGW's `bin` directory to your Windows `PATH` environment variable
3. Open **Command Prompt** or **PowerShell**
4. Navigate to the project directory:
   ```cmd
   cd "C:\Users\YourUsername\Desktop\group 15"
   ```
5. Compile all source files manually:
   ```cmd
   g++ -std=c++17 -Wall -Wextra -pedantic -o WageCalculator.exe main.cpp Employee.cpp InputValidator.cpp InputHandler.cpp WageCalculator.cpp Payslip.cpp Utils.cpp
   ```
6. You should see `WageCalculator.exe` appear in the project directory

#### Method 3: Using CMake (Recommended for Cross-Platform)
1. Install [CMake](https://cmake.org/download/) and a C++ compiler (Visual Studio or MinGW)
2. Open **Command Prompt** or **PowerShell**
3. Navigate to the project directory:
   ```cmd
   cd "C:\Users\YourUsername\Desktop\group 15"
   ```
4. Create a build directory, navigate into it, generate build files, and compile:
   ```cmd
   mkdir build
   cd build
   cmake .. -G "MinGW Makefiles"  # Or "Visual Studio 17 2022" for MSVC
   cmake --build .
   ```
5. The executable will be in the `build` directory

---

## How to Use

### macOS / Linux
1. Run the compiled executable (from the project directory if using Make):
   ```bash
   ./WageCalculator
   ```

### Windows
1. Open **Command Prompt** or **PowerShell**
2. Navigate to the directory with your executable:
   ```cmd
   cd "C:\Users\YourUsername\Desktop\group 15"
   ```
3. Run the executable:
   ```cmd
   WageCalculator.exe
   ```
   (Or double-click `WageCalculator.exe` in File Explorer!)

---

#### For All Platforms
Follow the on-screen prompts one by one, entering:
1. Employee name (cannot be empty)
2. Employee ID (positive integer, max 999999)
3. Department (cannot be empty)
4. Hourly rate (positive number, max 10000.0)
5. Hours worked (non-negative number, max 1000.0)
6. Pension deduction (non-negative number, max 1000000.0)
7. Loan deduction (non-negative number, max 1000000.0)
8. Insurance deduction (non-negative number, max 1000000.0)
9. Other deductions (non-negative number, max 1000000.0)

If you enter invalid input, the program will politely ask you to try again. A professional payslip will be generated and displayed automatically!

## Troubleshooting

### General
- **"error: ‘std::function’ was not declared"**: Make sure you're compiling with C++17 or later (the Makefile and CMakeLists.txt already set this)
- **No executable appears**: Clean all build files and recompile from scratch

### macOS / Linux
- **"command not found: make"**:
  - macOS: Install Xcode Command Line Tools with `xcode-select --install`
  - Linux: Install with `sudo apt install make` (Debian/Ubuntu) or `sudo dnf install make` (Fedora)
- **"permission denied: ./WageCalculator"**: Make the file executable with `chmod +x WageCalculator`

### Windows
- **"g++ is not recognized"**: Make sure MinGW or your compiler's `bin` directory is in your Windows `PATH`
- **Visual Studio build errors**: Double-check that you're using a C++17-compatible project configuration (Project > Properties > C/C++ > Language > C++ Language Standard)
- **"The system cannot find the file specified"**: Make sure you're in the correct directory with `cd`!

## Classes

### Employee
Represents an employee with all necessary data:
- Name, ID, Department
- Hourly rate, Hours worked
- Getters (safe read access) and setters (with built-in validation)

### InputValidator
Provides validation methods for all user inputs:
- Non-empty strings for names/departments
- Positive numbers for IDs, hourly rates
- Non-negative numbers for hours/deductions
- Reasonable maximum limits to prevent mistakes

### InputHandler
Handles all user interaction:
- Prompts for input
- Validates input using InputValidator
- Retries until valid input is received
- Creates Employee objects from validated input

### WageCalculator
Contains all the calculation logic:
- Regular pay: min(hours, 40) × hourly rate
- Overtime pay: max(hours - 40, 0) × 1.5 × hourly rate
- Gross pay: regular pay + overtime pay
- Tax: 5% of gross pay
- Net pay: gross pay - total deductions (tax + pension + loan + insurance + other)

### Payslip
Stores all payslip data and displays it in a professional, readable format:
- Clear sections for employee info, wage calculations, and deductions
- Formatted currency with 2 decimal places
- Final net pay prominently displayed

## Documentation
All classes, methods, and functions are documented with inline comments explaining their purpose, parameters, and behavior. Check the .h files for class interfaces and .cpp files for implementation details!

## Lecturer Preparation
A complete list of common questions a lecturer might ask, plus sample answers, is available in the [LECTURER_QUESTIONS.md](./LECTURER_QUESTIONS.md) file!
