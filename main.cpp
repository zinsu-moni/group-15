// main.cpp - Entry point for the Wage Calculator application
// This file contains the main function and application flow

#include <iostream>
#include <stdexcept>
#include "InputHandler.h"
#include "Employee.h"
#include "WageCalculator.h"
#include "Payslip.h"

int main() {
    try {
        std::cout << "Wage Calculator Application\n";
        std::cout << "===========================\n\n";
        
        InputHandler inputHandler;
        Employee employee = inputHandler.getEmployeeFromInput();
        
        // Get deductions from user
        std::cout << "\nEnter Deductions:\n";
        double pension = inputHandler.getValidatedDeduction("Enter Pension Deduction: ");
        double loan = inputHandler.getValidatedDeduction("Enter Loan Deduction: ");
        double insurance = inputHandler.getValidatedDeduction("Enter Insurance Deduction: ");
        double other = inputHandler.getValidatedDeduction("Enter Other Deductions: ");
        
        WageCalculator calculator;
        double regularPay = calculator.calculateRegularPay(employee);
        double overtimePay = calculator.calculateOvertimePay(employee);
        double grossPay = calculator.calculateGrossPay(employee);
        double tax = calculator.calculateDeductions(grossPay);
        double totalDeductions = tax + pension + loan + insurance + other;
        double netPay = calculator.calculateNetPay(grossPay, totalDeductions);
        
        // Create and display payslip
        Payslip payslip;
        payslip.setEmployee(employee);
        payslip.setRegularPay(regularPay);
        payslip.setOvertimePay(overtimePay);
        payslip.setGrossPay(grossPay);
        payslip.setTax(tax);
        payslip.setPension(pension);
        payslip.setLoan(loan);
        payslip.setInsurance(insurance);
        payslip.setOtherDeductions(other);
        payslip.setNetPay(netPay);
        
        payslip.display();
        
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }
}