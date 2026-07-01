// Payslip.cpp - Implementation file for the Payslip class

#include "Payslip.h"
#include <iostream>
#include <iomanip>

// Constructor
Payslip::Payslip() 
    : regularPay(0.0), overtimePay(0.0), grossPay(0.0), 
      tax(0.0), pension(0.0), loan(0.0), insurance(0.0), 
      otherDeductions(0.0), netPay(0.0) {
}

// Destructor
Payslip::~Payslip() {
}

// Getters and Setters
const Employee& Payslip::getEmployee() const {
    return employee;
}

void Payslip::setEmployee(const Employee& employee) {
    this->employee = employee;
}

double Payslip::getRegularPay() const {
    return regularPay;
}

void Payslip::setRegularPay(double pay) {
    this->regularPay = pay;
}

double Payslip::getOvertimePay() const {
    return overtimePay;
}

void Payslip::setOvertimePay(double pay) {
    this->overtimePay = pay;
}

double Payslip::getGrossPay() const {
    return grossPay;
}

void Payslip::setGrossPay(double pay) {
    this->grossPay = pay;
}

double Payslip::getTax() const {
    return tax;
}

void Payslip::setTax(double tax) {
    this->tax = tax;
}

double Payslip::getPension() const {
    return pension;
}

void Payslip::setPension(double pension) {
    this->pension = pension;
}

double Payslip::getLoan() const {
    return loan;
}

void Payslip::setLoan(double loan) {
    this->loan = loan;
}

double Payslip::getInsurance() const {
    return insurance;
}

void Payslip::setInsurance(double insurance) {
    this->insurance = insurance;
}

double Payslip::getOtherDeductions() const {
    return otherDeductions;
}

void Payslip::setOtherDeductions(double other) {
    this->otherDeductions = other;
}

double Payslip::getTotalDeductions() const {
    return tax + pension + loan + insurance + otherDeductions;
}

double Payslip::getNetPay() const {
    return netPay;
}

void Payslip::setNetPay(double pay) {
    this->netPay = pay;
}

// Display method
void Payslip::display() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n=============================\n";
    std::cout << "      EMPLOYEE PAYSLIP       \n";
    std::cout << "=============================\n\n";
    
    std::cout << "Employee Name: " << employee.getName() << "\n";
    std::cout << "Employee ID:   " << employee.getId() << "\n";
    std::cout << "Department:    " << employee.getDepartment() << "\n\n";
    
    std::cout << "Hours Worked:  " << employee.getHoursWorked() << "\n";
    std::cout << "Hourly Rate:  $" << employee.getHourlyRate() << "\n\n";
    
    std::cout << "Regular Pay:  $" << regularPay << "\n";
    std::cout << "Overtime Pay: $" << overtimePay << "\n";
    std::cout << "Gross Pay:    $" << grossPay << "\n\n";
    
    std::cout << "Deductions:\n";
    std::cout << "Tax:          $" << tax << "\n";
    std::cout << "Pension:      $" << pension << "\n";
    std::cout << "Loan:         $" << loan << "\n";
    std::cout << "Insurance:    $" << insurance << "\n";
    std::cout << "Other:        $" << otherDeductions << "\n";
    std::cout << "Total Deductions: $" << getTotalDeductions() << "\n\n";
    
    std::cout << "Net Pay:      $" << netPay << "\n";
    std::cout << "=============================\n";
}