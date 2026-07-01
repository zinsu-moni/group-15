# CMakeLists.txt - Build configuration for Wage Calculator project
cmake_minimum_required(VERSION 3.10)
project(WageCalculator)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(WageCalculator
    main.cpp
    Employee.cpp
    InputValidator.cpp
    WageCalculator.cpp
    Payslip.cpp
    Utils.cpp
)
