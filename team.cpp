#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "team.h"

using namespace std;

Team::Team() : teamName(""), pAllPlayers(nullptr), numberOfPlayers(0), numberOfWins(0), numberOfLoses(0) {

}

Team::Team(const string& teamName, const Owner& owner, const Court& court, Player** players, int numberOfPlayers)
    : teamName(teamName), rOwner(owner), rCourt(court), numberOfWins(0), numberOfLoses(0), numberOfPlayers(numberOfPlayers) {

    pAllPlayers = new Player * [numberOfPlayers];
    copyPlayers(players, numberOfPlayers);
}

// Copy Constructor
Team::Team(const Team& other)
    : teamName(other.teamName), rOwner(other.rOwner), rCourt(other.rCourt), numberOfWins(other.numberOfWins), numberOfLoses(other.numberOfLoses), numberOfPlayers(other.numberOfPlayers) {

    pAllPlayers = new Player * [numberOfPlayers];
    copyPlayers(other.pAllPlayers, numberOfPlayers);
}

// Move Constructor
Team::Team(Team&& other) noexcept
    : teamName(move(other.teamName)), rOwner(move(other.rOwner)), rCourt(move(other.rCourt)), numberOfWins(other.numberOfWins), numberOfLoses(other.numberOfLoses), numberOfPlayers(other.numberOfPlayers), pAllPlayers(other.pAllPlayers) {

    other.pAllPlayers = nullptr;
    other.numberOfPlayers = 0;
}

// Destructor
Team::~Team() {
    for (int i = 0; i < numberOfPlayers; ++i) {
        delete pAllPlayers[i];
    }
    delete[] pAllPlayers;
}

// Setters
void Team::setName(const string& name) {
    teamName = name;
}

void Team::setNumberOfWins(int wins) {
    numberOfWins = wins;
}

void Team::setNumberOfLoses(int loses) {
    numberOfLoses = loses;
}

void Team::setNumberOfPlayers(int newNumOfPlayers) {
    if (newNumOfPlayers < numberOfPlayers) {
        for (int i = newNumOfPlayers; i < numberOfPlayers; ++i) {
            delete pAllPlayers[i];
        }
    }
    Player** newPlayers = new Player * [newNumOfPlayers];
    for (int i = 0; i < newNumOfPlayers && i < numberOfPlayers; ++i) {
        newPlayers[i] = pAllPlayers[i];
    }
    delete[] pAllPlayers;
    pAllPlayers = newPlayers;
    numberOfPlayers = newNumOfPlayers;
}

void Team::setOwner(const Owner& other) {
    this->rOwner = other;
}

// Getters
const string& Team::getName() const {
    return teamName;
}

int Team::getNumberOfWins() const {
    return numberOfWins;
}

int Team::getNumberOfLoses() const {
    return numberOfLoses;
}

int Team::getNumberOfPlayers() const {
    return numberOfPlayers;
}

const Court& Team::getCourt() const {
    return rCourt;
}

void Team::incrementWins() {
    numberOfWins++;
}

void Team::incrementLosses() {
    numberOfLoses++;
}

// Overloaded + operator to add a Player
const Team& Team::operator+(const Player& other) {
    Player** newPlayers = new Player * [numberOfPlayers + 1];
    for (int i = 0; i < numberOfPlayers; ++i) {
        newPlayers[i] = pAllPlayers[i];
    }
    newPlayers[numberOfPlayers] = new Player(other);
    delete[] pAllPlayers;
    pAllPlayers = newPlayers;
    numberOfPlayers++;
    return *this;
}

Team& Team::operator=(const Team& other) {
    if (this != &other) {
        teamName = other.teamName;
        for (int i = 0; i < numberOfPlayers; ++i) {
            delete pAllPlayers[i];
        }
        delete[] pAllPlayers;
        rOwner = other.rOwner;
        rCourt = other.rCourt;
        numberOfWins = other.numberOfWins;
        numberOfLoses = other.numberOfLoses;
        numberOfPlayers = other.numberOfPlayers;
        pAllPlayers = new Player * [numberOfPlayers];
        copyPlayers(other.pAllPlayers, numberOfPlayers);
    }
    return *this;
}

// Overloaded << operator to print Team details
ostream& operator<<(ostream& os, const Team& team) {
    os << "Team Name: " << team.getName() << endl << endl;
    os << "Owner: " << team.rOwner.getName() << ", Budget: " << team.rOwner.getBudget() << endl << endl;
    os << team.rCourt << endl << endl;
    os << "Record: " << team.getNumberOfWins() << " - " << team.getNumberOfLoses() << endl << endl;
    os << "Players: " << endl;
    for (int i = 0; i < team.getNumberOfPlayers(); ++i) {
        os << "#" << (team.pAllPlayers[i])->getPlayerNumber() << ", " << (team.pAllPlayers[i])->getName() << ", " << (team.pAllPlayers[i])->positionNames[team.pAllPlayers[i]->getPlayerPosition()] << endl;
    }
    os << "----------------------------" << endl;
    return os;
}

void Team::copyPlayers(Player** players, int numberOfPlayers) {
    for (int i = 0; i < numberOfPlayers; ++i) {
        pAllPlayers[i] = new Player(*players[i]);
    }
}
