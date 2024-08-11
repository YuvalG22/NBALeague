#include "owner.h"
#include "date.h"
#include "league.h"
#include "person.h"
#include <iostream>
#include <limits>

using namespace std;

Owner::Owner() : Person(0, "Default Name", Date(), MALE, "Default Address"), budget(0.0f) {}

Owner::Owner(const int pid, const char* name, const Date& dob, const eGenderType gender, const char* address, const float budget)
    : Person(pid, name, dob, gender, address), budget(budget) {
}

void Owner::setBudget(const float budget) {
    this->budget = budget;
}

const float Owner::getBudget() const {
    return budget;
}

void Owner::toOs(std::ostream& os) const {
    os << "Budget: $" << getBudget() << endl;
    os << "-----------------------------";
}

std::ostream& operator<<(std::ostream& os, const Owner& o) {
    os << static_cast<const Person&>(o);
    return os;
}