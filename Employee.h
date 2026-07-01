// Employee.h - Header file for the Employee class
// This class represents an employee with all necessary information

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
public:
    // Default constructor
    Employee();
    
    // Parameterized constructor
    Employee(const std::string& name, int id, const std::string& department, 
             double hourlyRate, double hoursWorked);
    
    // Destructor
    ~Employee();
    
    // Getters
    std::string getName() const;
    int getId() const;
    std::string getDepartment() const;
    double getHourlyRate() const;
    double getHoursWorked() const;
    
    // Setters with validation
    void setName(const std::string& name);
    void setId(int id);
    void setDepartment(const std::string& department);
    void setHourlyRate(double rate);
    void setHoursWorked(double hours);

private:
    std::string name;
    int id;
    std::string department;
    double hourlyRate;
    double hoursWorked;
};

#endif // EMPLOYEE_H