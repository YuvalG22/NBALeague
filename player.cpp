#include "player.h"
#include "date.h"
#include "owner.h"
#include "person.h"
#include <iostream>
#include <limits>

using namespace std;

Player::Player(const Employee& e, const int playerNumber, ePositionType position, const int numberOfTitles, const int numberOfMatches, bool isOwner)
    : Person(e), Employee(e), playerNumber(playerNumber), position(position), numberOfTitles(numberOfTitles), numberOfMatches(numberOfMatches), isOwner(isOwner)
{}

// Constructor for player who is also an owner
Player::Player(const Employee& e, const Owner& o, const int playerNumber, ePositionType position, const int numberOfTitles, const int numberOfMatches, bool isOwner)
    : Person(e), Employee(e), Owner(o), playerNumber(playerNumber), position(position), numberOfTitles(numberOfTitles), numberOfMatches(numberOfMatches), isOwner(true)
{}

const int Player::getPlayerNumber() const {
    return playerNumber;
}

const Player::ePositionType Player::getPlayerPosition() const {
    return position;
}

const int Player::getPlayerTitles() const {
    return numberOfTitles;
}

const int Player::getPlayerMatches() const {
    return numberOfMatches;
}

int Player::getEnumSelection(const char* message, const char* const types[], const int numOfTypes)
{
    return 0;
}

void Player::setPlayerNumber(const int number) {
    playerNumber = number;
}

void Player::setPlayerPosition(const ePositionType pos) {
    position = pos;
}

void Player::setPlayerTitles(const int newTitles) {
    numberOfTitles = newTitles;
}

void Player::setPlayerMatches(const int newMatches) {
    numberOfMatches = newMatches;
}

const Player& Player::operator+() {
    ++numberOfTitles;
    return *this;
}

void Player::toOs(std::ostream& os) const {
    Employee::toOs(os);
    if (isOwner) {
        Owner::toOs(os);
    }
    os << "Player Details" << endl;
    os << "Player Number: " << playerNumber << endl;
    os << "Position: " << positionNames[position] << endl;
    os << "Number of Titles: " << numberOfTitles << endl;
    os << "Number of Matches: " << numberOfMatches << endl;
    os << "\n";
}

ostream& operator<<(ostream& os, const Player& player) {
    player.toOs(os);
    return os;
}

int getEnumSelection(const char* message, const char* const types[], const int numOfTypes)
{
    int enumChoice;
    do
    {
        cout << message << endl;
        for (int i = 0; i < numOfTypes; ++i)
        {
            cout << i + 1 << ") " << types[i] << endl;
        }
        cin >> enumChoice;
    } while (enumChoice < 1 || enumChoice > numOfTypes);

    return enumChoice - 1;  // Adjust to zero-based index
}


/*
Player* createPlayer() {
    int pid, playerNumber, numOfTitles, numOfMatches;
    char name[Person::MAX_STR_LEN], address[Person::MAX_STR_LEN];
    Person::eGenderType gender;
    Player::ePositionType position;
    float salary;
    int day, month, year;
    Date date;

    cout << "Please enter player's details:" << endl;
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

    cout << "Player Number: ";
    while (!(cin >> playerNumber)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number for player number: ";
    }

    cout << "Number of Titles: ";
    while (!(cin >> numOfTitles)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number for number of titles: ";
    }

    cout << "Number of Matches: ";
    while (!(cin >> numOfMatches)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number for number of matches: ";
    }
    position = static_cast<Player::ePositionType>(getEnumSelection("Please choose player's position:", Player::positionNames, Player::eNumOfTypes));

    // Assuming that the Player class has a constructor that accepts these parameters
    return new Player(Employee(pid, name, date, gender, address, salary), playerNumber, position, numOfTitles, numOfMatches, false);
}*/
