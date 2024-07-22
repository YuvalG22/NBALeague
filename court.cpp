#define _CRT_SECURE_NO_WARNINGS
#include "court.h"
#include <iostream>
using namespace std;

Court::Court() {

}

Court::Court(const char* courtName, const int numberOfSeats) {
    this->courtName = new char[strlen(courtName) + 1];
    strcpy(this->courtName, courtName);
    this->numberOfSeats = numberOfSeats;
}

// Copy Constructor
Court::Court(const Court& other) {
    this->courtName = new char[strlen(other.courtName) + 1];
    strcpy(this->courtName, other.courtName);
    this->numberOfSeats = other.numberOfSeats;
}

// Move Constructor
Court::Court(Court&& other) {
    this->courtName = other.courtName;
    this->numberOfSeats = other.numberOfSeats;
    other.courtName = nullptr;
    other.numberOfSeats = 0;
}

// Destructor
Court::~Court() {
    delete[] courtName;
}

// Getter for courtName
const char* Court::getCourtName() const {
    return courtName;
}

// Getter for numberOfSeats
const int Court::getNumberOfSeats() const {
    return numberOfSeats;
}

// Setter for courtName
void Court::setCourtName(const char* name) {
    delete[] courtName;
    courtName = new char[strlen(name) + 1];
    strcpy(courtName, name);
}

Court& Court::operator=(const Court& other) {
    if (this != &other) { // Check for self-assignment
        delete[] courtName; // Delete existing courtName

        // Allocate memory for new courtName and copy the string
        courtName = new char[strlen(other.courtName) + 1];
        strcpy(courtName, other.courtName);

        numberOfSeats = other.numberOfSeats; // Copy numberOfSeats
    }
    return *this;
}

// Friend function to overload the << operator
ostream& operator<<(ostream& os, const Court& court) {
    os << "Court Name: " << court.courtName << ", Number of Seats: " << court.numberOfSeats;
    return os;
}