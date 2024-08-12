#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <iostream>
#include "person.h"
using namespace std;

class Employee : virtual public Person
{
protected:
	float salary;

public:
	Employee(const int pid, const string& name, const Date& dob, const eGenderType gender, const string& address, const float salary);

	virtual void toOs(ostream& os) const override;

	const float getSalary() const;
	void setSalary(const float salary);
	Employee& operator=(const Employee& other);
	const Employee& operator+(const float valueToAdd);
	friend ostream& operator<<(ostream& os, const Employee& e);

};

#endif // __EMPLOYEE_H