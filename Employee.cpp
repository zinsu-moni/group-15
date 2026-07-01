// Employee.cpp - Implementation file for the Employee class

#include "Employee.h"
#include <stdexcept>

// Default constructor
Employee::Employee() : name(""), id(0), department(""), hourlyRate(0.0), hoursWorked(0.0) {
}

// Parameterized constructor
Employee::Employee(const std::string& name, int id, const std::string& department, 
                   double hourlyRate, double hoursWorked) {
    setName(name);
    setId(id);
    setDepartment(department);
    setHourlyRate(hourlyRate);
    setHoursWorked(hoursWorked);
}

// Destructor
Employee::~Employee() {
}

// Getters
std::string Employee::getName() const {
    return name;
}

int Employee::getId() const {
    return id;
}

std::string Employee::getDepartment() const {
    return department;
}

double Employee::getHourlyRate() const {
    return hourlyRate;
}

double Employee::getHoursWorked() const {
    return hoursWorked;
}

// Setters with validation
void Employee::setName(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument("Name cannot be empty");
    }
    this->name = name;
}

void Employee::setId(int id) {
    if (id <= 0) {
        throw std::invalid_argument("ID must be a positive integer");
    }
    this->id = id;
}

void Employee::setDepartment(const std::string& department) {
    if (department.empty()) {
        throw std::invalid_argument("Department cannot be empty");
    }
    this->department = department;
}

void Employee::setHourlyRate(double rate) {
    if (rate <= 0.0) {
        throw std::invalid_argument("Hourly rate must be positive");
    }
    this->hourlyRate = rate;
}

void Employee::setHoursWorked(double hours) {
    if (hours < 0.0) {
        throw std::invalid_argument("Hours worked cannot be negative");
    }
    this->hoursWorked = hours;
}