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
    os << "Player Number: #" << playerNumber << endl;
    os << "Position: " << positionNames[position] << endl;
    os << "Number of Titles: " << numberOfTitles << endl;
    os << "Number of Matches: " << numberOfMatches << endl;
    os << "-----------------------------";
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
