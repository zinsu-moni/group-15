// InputHandler.cpp - Implementation file for handling user input

#include "InputHandler.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

// Constructor
InputHandler::InputHandler() {
}

// Destructor
InputHandler::~InputHandler() {
}

// Methods to get validated input
std::string InputHandler::getValidatedName(const std::string& prompt) const {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        if (validator.isValidName(input)) {
            return input;
        }
        
        std::cout << "Error: Name cannot be empty. Please try again.\n";
    }
}

int InputHandler::getValidatedId(const std::string& prompt) const {
    return getValidatedNumber<int>(
        prompt,
        "Error: Invalid input. Please enter a valid positive integer.",
        "Error: ID must be a positive integer between 1 and " + std::to_string(InputValidator::MAX_ID) + ". Please try again.",
        [this](int value) { return validator.isValidId(value); }
    );
}

std::string InputHandler::getValidatedDepartment(const std::string& prompt) const {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        if (!input.empty()) {
            return input;
        }
        
        std::cout << "Error: Department cannot be empty. Please try again.\n";
    }
}

double InputHandler::getValidatedHourlyRate(const std::string& prompt) const {
    return getValidatedNumber<double>(
        prompt,
        "Error: Invalid input. Please enter a valid number.",
        "Error: Hourly rate must be a positive number up to " + std::to_string(InputValidator::MAX_HOURLY_RATE) + ". Please try again.",
        [this](double value) { return validator.isValidHourlyRate(value); }
    );
}

double InputHandler::getValidatedHoursWorked(const std::string& prompt) const {
    return getValidatedNumber<double>(
        prompt,
        "Error: Invalid input. Please enter a valid number.",
        "Error: Hours worked must be a non-negative number up to " + std::to_string(InputValidator::MAX_HOURS_WORKED) + ". Please try again.",
        [this](double value) { return validator.isValidHoursWorked(value); }
    );
}

double InputHandler::getValidatedDeduction(const std::string& prompt) const {
    return getValidatedNumber<double>(
        prompt,
        "Error: Invalid input. Please enter a valid number.",
        "Error: Deduction must be a non-negative number up to " + std::to_string(InputValidator::MAX_DEDUCTION) + ". Please try again.",
        [this](double value) { return validator.isValidDeduction(value); }
    );
}

// Method to create an Employee from user input
Employee InputHandler::getEmployeeFromInput() const {
    std::string name = getValidatedName("Enter Employee Name: ");
    int id = getValidatedId("Enter Employee ID: ");
    std::string department = getValidatedDepartment("Enter Department: ");
    double hourlyRate = getValidatedHourlyRate("Enter Hourly Rate: ");
    double hoursWorked = getValidatedHoursWorked("Enter Hours Worked: ");
    
    return Employee(name, id, department, hourlyRate, hoursWorked);
}
