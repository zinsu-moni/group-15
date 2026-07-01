// InputValidator.cpp - Implementation file for input validation utilities

#include "InputValidator.h"

// Constructor
InputValidator::InputValidator() {
}

// Destructor
InputValidator::~InputValidator() {
}

// Validation methods
bool InputValidator::isValidName(const std::string& name) const {
    return !name.empty();
}

bool InputValidator::isValidId(int id) const {
    return id > 0 && id <= MAX_ID;
}

bool InputValidator::isValidHourlyRate(double rate) const {
    return rate > 0.0 && rate <= MAX_HOURLY_RATE;
}

bool InputValidator::isValidHoursWorked(double hours) const {
    return hours >= 0.0 && hours <= MAX_HOURS_WORKED;
}

bool InputValidator::isValidDeduction(double deduction) const {
    // Deduction must be non-negative and not exceed maximum
    return deduction >= 0.0 && deduction <= MAX_DEDUCTION;
}