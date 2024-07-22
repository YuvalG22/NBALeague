#ifndef __COURT_H
#define __COURT_H

#include <iostream>
using namespace std;

class Court
{
protected:
	char* courtName;
	int numberOfSeats;

public:
	Court();
	Court(const char* courtName, const int numberOfSeats);
	Court(const Court& other);
	Court(Court&& other);
	~Court();

	const char* getCourtName() const;
	const int getNumberOfSeats() const;
	void setCourtName(const char* name);
	Court& operator=(const Court& other);
	friend ostream& operator<<(ostream& os, const Court& court);

};

#endif // __COURT_H