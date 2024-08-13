#include <iostream>
#include "employee.h"

Employee::Employee(const int pid, const string& name, const Date& dob, const eGenderType gender, const string& address, const float salary)
    : Person(pid, name, dob, gender, address), salary(salary) {
}

const float Employee::getSalary() const {
    return salary;
}

void Employee::setSalary(const float salary) {
    this->salary = salary;
}

const Employee& Employee::operator+(const float valueToAdd) {
    salary += valueToAdd;
    return *this;
}

void Employee::toOs(ostream& os) const {
    os << "Salary: $" << getSalary() << endl;
    os << "\n";
}

ostream& operator<<(ostream& os, const Employee& e) {
    e.toOs(os);
    return os;
}