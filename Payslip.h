// Payslip.h - Header file for the Payslip class
// This class represents a payslip with payment details

#ifndef PAYSLIP_H
#define PAYSLIP_H

#include "Employee.h"
#include <string>

class Payslip {
public:
    // Constructor
    Payslip();
    
    // Destructor
    ~Payslip();
    
    // Getters and Setters
    const Employee& getEmployee() const;
    void setEmployee(const Employee& employee);
    
    double getRegularPay() const;
    void setRegularPay(double pay);
    
    double getOvertimePay() const;
    void setOvertimePay(double pay);
    
    double getGrossPay() const;
    void setGrossPay(double pay);
    
    double getTax() const;
    void setTax(double tax);
    
    double getPension() const;
    void setPension(double pension);
    
    double getLoan() const;
    void setLoan(double loan);
    
    double getInsurance() const;
    void setInsurance(double insurance);
    
    double getOtherDeductions() const;
    void setOtherDeductions(double other);
    
    double getTotalDeductions() const;
    
    double getNetPay() const;
    void setNetPay(double pay);
    
    // Display method
    void display() const;

private:
    Employee employee;
    double regularPay;
    double overtimePay;
    double grossPay;
    double tax;
    double pension;
    double loan;
    double insurance;
    double otherDeductions;
    double netPay;
};

#endif // PAYSLIP_H