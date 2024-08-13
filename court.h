#ifndef __COURT_H
#define __COURT_H

#include <iostream>
using namespace std;

class Court
{
protected:
	string courtName;
	int numberOfSeats;

public:
	Court();
	Court(const string& courtName, const int numberOfSeats);

	const string& getCourtName() const;
	int getNumberOfSeats() const;
	void setCourtName(const string& name);
	friend ostream& operator<<(ostream& os, const Court& court);

};

#endif // __COURT_H