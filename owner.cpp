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
    os << "Owner Details" << endl;
    os << "Budget: $" << getBudget() << std::endl;
    os << "\n";
}

std::ostream& operator<<(std::ostream& os, const Owner& o) {
    o.toOs(os);
    return os;
}

/*
Owner* createOwner() {
    int pid;
    char name[Person::MAX_STR_LEN], address[Person::MAX_STR_LEN];
    Person::eGenderType gender;
    float budget;
    int day, month, year;
    Date date;

    cout << "Please enter owner's details:" << endl;
    cout << "ID: ";
    while (!(cin >> pid)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number for ID: ";
    }
    cin.ignore(); // Ignore leftover newline character

    cout << "Name: ";
    cin.getline(name, Person::MAX_STR_LEN);

    cout << "Date of Birth:" << endl;
    do {
        cout << "Day: ";
        while (!(cin >> day)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number for day: ";
        }
    } while (day < 1 || day > 31);

    do {
        cout << "Month: ";
        while (!(cin >> month)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number for month: ";
        }
    } while (month < 1 || month > 12);

    do {
        cout << "Year: ";
        while (!(cin >> year)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number for year: ";
        }
    } while (year < 1000 || year > 9999);
    date = Date(day, month, year);

    cout << "Gender (0 for Male, 1 for Female): ";
    int genderInput;
    while (!(cin >> genderInput) || (genderInput != 0 && genderInput != 1)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter 0 for Male or 1 for Female: ";
    }
    gender = static_cast<Person::eGenderType>(genderInput);
    cin.ignore(); // Ignore leftover newline character

    cout << "Address: ";
    cin.getline(address, Person::MAX_STR_LEN);

    cout << "Budget: ";
    while (!(cin >> budget)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number for budget: ";
    }

    return new Owner(pid, name, date, gender, address, budget);
}*/