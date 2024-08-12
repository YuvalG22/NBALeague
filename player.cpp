#include "player.h"
#include "date.h"
#include "owner.h"
#include "person.h"
#include <iostream>
#include <limits>

using namespace std;

Player::Player(const Employee& e, int playerNumber, ePositionType position, int numberOfTitles, int numberOfMatches, bool isOwner)
    : Person(e), Employee(e), playerNumber(playerNumber), position(position), numberOfTitles(numberOfTitles), numberOfMatches(numberOfMatches), isOwner(isOwner)
{}

// Constructor for player who is also an owner
Player::Player(const Employee& e, const Owner& o, int playerNumber, ePositionType position, int numberOfTitles, int numberOfMatches, bool isOwner)
    : Person(e), Employee(e), Owner(o), playerNumber(playerNumber), position(position), numberOfTitles(numberOfTitles), numberOfMatches(numberOfMatches), isOwner(true)
{}

int Player::getPlayerNumber() const {
    return playerNumber;
}

Player::ePositionType Player::getPlayerPosition() const {
    return position;
}

int Player::getPlayerTitles() const {
    return numberOfTitles;
}

int Player::getPlayerMatches() const {
    return numberOfMatches;
}

void Player::setPlayerNumber(int number) {
    playerNumber = number;
}

void Player::setPlayerPosition(ePositionType pos) {
    position = pos;
}

void Player::setPlayerTitles(int newTitles) {
    numberOfTitles = newTitles;
}

void Player::setPlayerMatches(int newMatches) {
    numberOfMatches = newMatches;
}

const Player& Player::operator+() {
    ++numberOfTitles;
    return *this;
}

void Player::toOs(ostream& os) const {
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
