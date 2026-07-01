// WageCalculator.cpp - Implementation file for the WageCalculator class

#include "WageCalculator.h"
#include <algorithm> // For std::min and std::max

// Constructor
WageCalculator::WageCalculator() {
}

// Destructor
WageCalculator::~WageCalculator() {
}

// Calculation methods
double WageCalculator::calculateRegularPay(const Employee& employee) const {
    // Regular Pay Formula: minimum of hours worked and 40, multiplied by hourly rate
    // This ensures we only pay for up to 40 regular hours
    double regularHours = std::min(employee.getHoursWorked(), 40.0);
    return regularHours * employee.getHourlyRate();
}

double WageCalculator::calculateOvertimePay(const Employee& employee) const {
    // Overtime Pay Formula: maximum of (hours worked - 40, 0), multiplied by 1.5 × hourly rate
    // This calculates pay for hours over 40 at time-and-a-half
    double overtimeHours = std::max(employee.getHoursWorked() - 40.0, 0.0);
    double overtimeRate = 1.5 * employee.getHourlyRate();
    return overtimeHours * overtimeRate;
}

double WageCalculator::calculateGrossPay(const Employee& employee) const {
    // Gross Pay Formula: Regular Pay + Overtime Pay
    // This is total pay before any deductions
    return calculateRegularPay(employee) + calculateOvertimePay(employee);
}

double WageCalculator::calculateDeductions(double grossPay) const {
    // Deductions (Tax) Formula: Gross Pay × TAX_RATE (5%)
    // This calculates the amount of tax to be deducted
    return grossPay * TAX_RATE;
}

double WageCalculator::calculateNetPay(double grossPay, double deductions) const {
    // Net Pay Formula: Gross Pay - Deductions
    // This is the final amount the employee takes home
    return grossPay - deductions;
}