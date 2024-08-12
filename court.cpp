#include "court.h"
#include <iostream>
#include <string>

using namespace std;

// Default Constructor
Court::Court() : courtName(""), numberOfSeats(0) {}

// Parameterized Constructor
Court::Court(const string& courtName, const int numberOfSeats)
    : courtName(courtName), numberOfSeats(numberOfSeats) {}

// Copy Constructor
Court::Court(const Court& other)
    : courtName(other.courtName), numberOfSeats(other.numberOfSeats) {}

// Move Constructor
Court::Court(Court&& other) 
    : courtName(move(other.courtName)), numberOfSeats(other.numberOfSeats) {
    other.numberOfSeats = 0; // Reset other object's seats
}

// Destructor
Court::~Court() = default; 

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

// Assignment Operator
Court& Court::operator=(const Court& other) {
    if (this != &other) { // Check for self-assignment
        courtName = other.courtName;
        numberOfSeats = other.numberOfSeats;
    }
    return *this;
}

// Overloaded << operator
ostream& operator<<(ostream& os, const Court& court) {
    os << "Court Name: " << court.courtName << ", Number of Seats: " << court.numberOfSeats;
    return os;
}
