#include "owner.h"
#include <iostream>

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
    os << "Owner Details" << endl;
    os << "Budget: $" << getBudget() << std::endl;
    os << "\n";
}

std::ostream& operator<<(std::ostream& os, const Owner& o) {
    o.toOs(os);
    return os;
}