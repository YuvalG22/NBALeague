#include <iostream>
#include "date.h"

Date::Date() {
	this->day = 1;
	this->month = 1;
	this->year = 2000;
}

Date::Date(const int day, const int month, const int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
	os << date.day << "/" << date.month << "/" << date.year;
	return os;
}



