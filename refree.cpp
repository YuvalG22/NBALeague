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

Refree& Refree::operator=(const Refree& other) {
    if (this != &other) {
        Employee::operator=(other);

        rank = other.rank;
        numberOfMatches = other.numberOfMatches;
    }
    return *this;
}

void Refree::toOs(ostream& os) const {
    Employee::toOs(os);
    os << "Referee Details" << endl;
    os << "Rank: " << getRank() << endl;
    os << "Number of Matches: " << getNumberOfMatches() << endl;
    os << "\n";
}

ostream& operator<<(ostream& os, const Refree& ref) {
    ref.toOs(os);
    return os;
}

/*
Refree* createRefree() {
    int pid, numOfMatches;
    char name[Person::MAX_STR_LEN], address[Person::MAX_STR_LEN];
    Person::eGenderType gender;
    float salary, rank;
    int day, month, year;
    Date date;

    cout << "Please enter referee's details:" << endl;
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

    cout << "Salary: ";
    while (!(cin >> salary)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number for salary: ";
    }

    cout << "Rank: ";
    while (!(cin >> rank)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number for rank: ";
    }

    cout << "Number of Matches: ";
    while (!(cin >> numOfMatches)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number for number of matches: ";
    }

    return new Refree(Employee(pid, name, date, gender, address, salary), rank, numOfMatches);
}
*/