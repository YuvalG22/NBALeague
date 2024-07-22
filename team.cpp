#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "team.h"

Team::Team() : teamName(nullptr), pAllPlayers(nullptr), numberOfWins(0), numberOfLoses(0), numberOfPlayers(0) {}

Team::Team(const char* teamName, const Owner& owner, const Court& court, const Player* players)
    : rOwner(owner), rCourt(court), numberOfWins(0), numberOfLoses(0), numberOfPlayers(0) {
    this->teamName = new char[strlen(teamName) + 1];
    strcpy(this->teamName, teamName);

    pAllPlayers = new Player * [numberOfPlayers];
    copyPlayers(players);
}

// Copy Constructor
Team::Team(const Team& other)
    : rOwner(other.rOwner), rCourt(other.rCourt), numberOfWins(other.numberOfWins), numberOfLoses(other.numberOfLoses), numberOfPlayers(other.numberOfPlayers) {
    teamName = new char[strlen(other.teamName) + 1];
    strcpy(teamName, other.teamName);

    pAllPlayers = new Player * [numberOfPlayers];
    copyPlayers(*other.pAllPlayers);
}

// Move Constructor
Team::Team(Team&& other)
    : teamName(other.teamName), rOwner(move(other.rOwner)), rCourt(move(other.rCourt)), numberOfWins(other.numberOfWins), numberOfLoses(other.numberOfLoses), numberOfPlayers(other.numberOfPlayers), pAllPlayers(other.pAllPlayers) {
    other.teamName = nullptr;
    other.pAllPlayers = nullptr;
}

// Destructor
Team::~Team() {
    delete[] teamName;
    for (int i = 0; i < numberOfPlayers; ++i) {
        delete pAllPlayers[i];
    }
    delete[] pAllPlayers;
}

// Setters
void Team::setName(const char* name) {
    delete[] teamName;
    teamName = new char[strlen(name) + 1];
    strcpy(teamName, name);
}

void Team::setNumberOfWins(const int wins) {
    numberOfWins = wins;
}

void Team::setNumberOfLoses(const int loses) {
    numberOfLoses = loses;
}

void Team::setNumberOfPlayers(const int newNumOfPlayers) {
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
const char* Team::getName() const {
    return teamName;
}

const int Team::getNumberOfWins() const {
    return numberOfWins;
}

const int Team::getNumberOfLoses() const {
    return numberOfLoses;
}

const int Team::getNumberOfPlayers() const {
    return numberOfPlayers;
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
        delete[]teamName;
        for (int i = 0; i < numberOfPlayers; ++i) {
            delete pAllPlayers[i];
        }
        delete[] pAllPlayers;
        rOwner = other.rOwner;
        rCourt = other.rCourt;
        numberOfWins = other.numberOfWins;
        numberOfLoses = other.numberOfLoses;
        numberOfPlayers = other.numberOfPlayers;
        teamName = new char[strlen(other.teamName) + 1];
        strcpy(teamName, other.teamName);
        pAllPlayers = new Player * [numberOfPlayers];
        copyPlayers(*other.pAllPlayers);
    }
    return *this;
}

// Overloaded << operator to print Team details
ostream& operator<<(ostream& os, const Team& team) {
    os << "Team Name: " << team.getName() << endl;
    os << "Owner: " << endl;
    os << "Court: " << endl;
    os << "Number of Wins: " << team.getNumberOfWins() << endl;
    os << "Number of Loses: " << team.getNumberOfLoses() << endl;
    os << "Number of Players: " << team.getNumberOfPlayers() << endl;
    os << "Players: " << endl;
    for (int i = 0; i < team.getNumberOfPlayers(); ++i) {
        os << (team.pAllPlayers[i]) << endl;
    }
    return os;
}

void Team::copyPlayers(const Player* players) {
    if (players) {
        for (int i = 0; i < numberOfPlayers; ++i) {
            pAllPlayers[i] = new Player(players[i]);
        }
    }
}