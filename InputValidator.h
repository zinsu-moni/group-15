// InputValidator.h - Header file for input validation utilities
// This class provides methods to validate user inputs

#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>

class InputValidator {
public:
    // Constructor
    InputValidator();
    
    // Destructor
    ~InputValidator();
    
    // Validation methods
    bool isValidName(const std::string& name) const;
    bool isValidId(int id) const;
    bool isValidHourlyRate(double rate) const;
    bool isValidHoursWorked(double hours) const;
    bool isValidDeduction(double deduction) const;
    
    // Constants for maximum values
    static constexpr int MAX_ID = 999999;
    static constexpr double MAX_HOURLY_RATE = 10000.0;
    static constexpr double MAX_HOURS_WORKED = 1000.0;
    static constexpr double MAX_DEDUCTION = 1000000.0;
};

#endif // INPUTVALIDATOR_H