#ifndef __OWNER_H
#define __OWNER_H

#include <iostream>
#include "person.h"
using namespace std;

class Owner : virtual public Person
{
protected:
	float budget;

public:
	Owner();
	Owner(const int pid, const char* name, const Date& dob, const eGenderType gender, const char* address, const float budget);
	
	void setBudget(const float budget);

	const float getBudget() const;

	virtual void toOs(ostream& os) const override;
	friend ostream& operator<<(ostream& os, const Owner& owner);
};

#endif // __OWNER_H