// WageCalculator.h - Header file for the WageCalculator class
// This class handles the wage calculation logic

#ifndef WAGECALCULATOR_H
#define WAGECALCULATOR_H

#include "Employee.h"

class WageCalculator {
public:
    // Constant for tax rate (5%)
    static constexpr double TAX_RATE = 0.05;
    
    // Constructor
    WageCalculator();
    
    // Destructor
    ~WageCalculator();
    
    // Calculation methods
    double calculateRegularPay(const Employee& employee) const;
    double calculateOvertimePay(const Employee& employee) const;
    double calculateGrossPay(const Employee& employee) const;
    double calculateDeductions(double grossPay) const;
    double calculateNetPay(double grossPay, double deductions) const;
};

#endif // WAGECALCULATOR_H