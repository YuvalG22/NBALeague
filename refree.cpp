#include "refree.h"
#include "date.h"
#include "person.h"
#include <iostream>
#include <limits>

using namespace std;

Refree::Refree(const Employee& e, const float rank, const int numberOfMatches)
    : Person(e), Employee(e), rank(rank), numberOfMatches(numberOfMatches) {
}

// Getter for rank
const float Refree::getRank() const {
    return rank;
}

// Getter for numberOfMatches
const int Refree::getNumberOfMatches() const {
    return numberOfMatches;
}

// Setter for rank
void Refree::setRank(const float rank) {
    this->rank = rank;
}

// Setter for numberOfMatches
void Refree::setNumberOfMatches(const int number) {
    numberOfMatches = number;
}

void Refree::toOs(ostream& os) const {
    Employee::toOs(os);
    os << "Rank: " << getRank() << endl;
    os << "Number of Matches: " << getNumberOfMatches() << endl;
    os << "-----------------------------";
}

ostream& operator<<(ostream& os, const Refree& ref) {
    ref.toOs(os);
    return os;
}