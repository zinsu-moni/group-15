// InputHandler.h - Header file for handling user input
// This class provides methods to get validated input from the user

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Employee.h"
#include "InputValidator.h"
#include <string>
#include <functional>
#include <iostream>
#include <limits>

class InputHandler {
public:
    // Constructor
    InputHandler();
    
    // Destructor
    ~InputHandler();
    
    // Methods to get validated input
    std::string getValidatedName(const std::string& prompt) const;
    int getValidatedId(const std::string& prompt) const;
    std::string getValidatedDepartment(const std::string& prompt) const;
    double getValidatedHourlyRate(const std::string& prompt) const;
    double getValidatedHoursWorked(const std::string& prompt) const;
    double getValidatedDeduction(const std::string& prompt) const;
    
    // Method to create an Employee from user input
    Employee getEmployeeFromInput() const;

private:
    InputValidator validator;
    
    // Helper function for validated numeric input
    template<typename T>
    T getValidatedNumber(const std::string& prompt, 
                        const std::string& invalidInputMsg,
                        const std::string& invalidValueMsg,
                        std::function<bool(T)> validatorFunc) const {
        T input;
        while (true) {
            std::cout << prompt;
            if (std::cin >> input) {
                if (validatorFunc(input)) {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    return input;
                } else {
                    std::cout << invalidValueMsg << std::endl;
                }
            } else {
                std::cout << invalidInputMsg << std::endl;
            }
            
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
};

#endif // INPUTHANDLER_H