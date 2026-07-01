# Wage Calculator

A professional console-based wage calculator application written in modern C++.

## Table of Contents
- [Features](#features)
- [Project Structure](#project-structure)
- [Compilation](#compilation)
- [Usage](#usage)
- [Classes](#classes)
- [Documentation](#documentation)

## Features
- Object-oriented design
- Input validation (prevents invalid numbers, negative values, empty inputs)
- Calculates regular pay, overtime pay, gross pay, tax, and net pay
- Generates professional payslip
- Follows C++ best practices

## Project Structure
```
group 15/
├── CMakeLists.txt     # CMake build configuration
├── Makefile           # Make build configuration
├── README.md          # Project documentation
├── .gitignore         # Git ignore rules
├── main.cpp           # Application entry point
├── Employee.h/cpp     # Employee class
├── InputHandler.h/cpp # User input handling
├── InputValidator.h/cpp # Input validation
├── Payslip.h/cpp      # Payslip generation and display
├── WageCalculator.h/cpp # Wage calculation logic
└── Utils.h/cpp        # Utility functions (placeholder)
```

## Compilation

### Using Make
```bash
make clean && make
```

### Using CMake
```bash
mkdir -p build && cd build
cmake .. && make
```

## Usage
Run the compiled executable:
```bash
./WageCalculator
```

Follow the on-screen prompts to enter:
1. Employee name
2. Employee ID
3. Department
4. Hourly rate
5. Hours worked
6. Pension deduction
7. Loan deduction
8. Insurance deduction
9. Other deductions

A professional payslip will be generated and displayed.

## Classes

### Employee
Represents an employee with:
- Name
- ID
- Department
- Hourly rate
- Hours worked

### InputValidator
Provides validation methods for all user inputs, including checking for valid ranges and non-negative values.

### InputHandler
Handles user interaction, prompting for inputs and validating them using InputValidator.

### WageCalculator
Contains the business logic for calculating:
- Regular pay
- Overtime pay (1.5x hourly rate for hours over 40)
- Gross pay
- Tax (5% of gross pay)
- Net pay

### Payslip
Represents a payslip and provides a method to display it in a professional format.

## Documentation

All classes and methods are documented with comments explaining their purpose and functionality.
