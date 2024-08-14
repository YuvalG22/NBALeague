#define _CRT_SECURE_NO_WARNINGS
#include "team.h"

Team::Team() : teamName(""), numberOfWins(0), numberOfLoses(0) {}

Team::Team(const string& teamName, const Owner& owner, const Court& court, const list<Player>& players)
    : teamName(teamName), rOwner(owner), rCourt(court), pAllPlayers(players), numberOfWins(0), numberOfLoses(0) {}

void Team::setName(const string& name) {
    teamName = name;
}

void Team::setNumberOfWins(int wins) {
    numberOfWins = wins;
}

void Team::setNumberOfLoses(int loses) {
    numberOfLoses = loses;
}

void Team::setOwner(const Owner& other) {
    rOwner = other;
}

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
    return pAllPlayers.size();
}

const Court& Team::getCourt() const {
    return rCourt;
}

// Non-const version of getPlayers
list<Player>& Team::getPlayers() {
    return pAllPlayers;
}

// Const version of getPlayers
const list<Player>& Team::getPlayers() const {
    return pAllPlayers;
}

void Team::incrementWins() {
    numberOfWins++;
}

void Team::incrementLosses() {
    numberOfLoses++;
}

const Team& Team::operator+(const Player& other) {
    pAllPlayers.push_back(other);
    return *this;
}

ostream& operator<<(ostream& os, const Team& team) {
    os << "Team Name: " << team.getName() << endl << endl;
    os << "Owner: " << team.rOwner.getName() << ", Budget: " << team.rOwner.getBudget() << endl << endl;
    os << team.rCourt << endl << endl;
    os << "Record: " << team.getNumberOfWins() << " - " << team.getNumberOfLoses() << endl << endl;
    os << "Players: " << endl;
    for (auto& player : team.getPlayers()) {  // Use non-const reference
        os << "#" << player.getPlayerNumber() << ", " << player.getName() << ", " << player.positionNames[player.getPlayerPosition()] << endl;
    }
    os << "----------------------------" << endl;
    return os;
}
