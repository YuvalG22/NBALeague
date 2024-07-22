#include <iostream>
#include "player.h"

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