#ifndef __REFREE_H
#define __REFREE_H

#include <iostream>
#include "employee.h"
using namespace std;

class Refree : public Employee
{
protected:
	float rank;
	int numberOfMatches;

public:
	Refree(const Employee& e, const float rank, const int numberOfMatches);

	const float getRank() const;
	const int getNumberOfMatches() const;

	void setRank(const float rank);
	void setNumberOfMatches(const int number);
	virtual void toOs(ostream& os) const override;
	friend ostream& operator<<(ostream& os, const Refree& ref);

};

#endif // __REFREE_H