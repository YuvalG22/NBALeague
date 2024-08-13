#include "court.h"
#include <iostream>
#include <string>

using namespace std;

// Default Constructor
Court::Court() : courtName(""), numberOfSeats(0) {}

// Parameterized Constructor
Court::Court(const string& courtName, const int numberOfSeats)
    : courtName(courtName), numberOfSeats(numberOfSeats) {} 

// Getter for courtName
const string& Court::getCourtName() const {
    return courtName;
}

// Getter for numberOfSeats
int Court::getNumberOfSeats() const {
    return numberOfSeats;
}

// Setter for courtName
void Court::setCourtName(const string& name) {
    courtName = name;
}

// Overloaded << operator
ostream& operator<<(ostream& os, const Court& court) {
    os << "Court Name: " << court.courtName << ", Number of Seats: " << court.numberOfSeats;
    return os;
}
