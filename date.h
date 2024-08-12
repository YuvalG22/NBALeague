#ifndef __DATE_H
#define __DATE_H
#include <iostream>
using namespace std;

class Date
{
	protected:
		int day;
		int month;
		int year;

	public:
		Date();
		Date(const int day, const int month, const int year);

		const int getDay() const { return day; }
		const int getMonth() const { return month; }
		const int getYear() const { return year; }

		friend ostream& operator<<(std::ostream& os, const Date& date);
};


#endif // __DATE_H