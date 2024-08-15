#define _CRT_SECURE_NO_WARNINGS
#include "team.h"

Team::Team() : teamName(""), numberOfWins(0), numberOfLoses(0) {}

Team::Team(const string& teamName, const Owner& owner, const Court& court, const list<Player*> players)
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

list<Player*> Team::getPlayers() {
    return pAllPlayers;
}

const list<Player*> Team::getPlayersConst() const{
    return pAllPlayers;
}

void Team::incrementWins() {
    numberOfWins++;
}

void Team::incrementLosses() {
    numberOfLoses++;
}

Team& Team::operator+(Player* other) {
    pAllPlayers.push_back(other);
    return *this;
}

void Team::updateMatch(bool won) {
    if (won) {
        incrementWins();
    }
    else {
        incrementLosses();
    }
}

ostream& operator<<(ostream& os, const Team& team) {
    os << "Team Name: " << team.getName() << endl << endl;
    os << "Owner: " << team.rOwner.getName() << ", Budget: " << team.rOwner.getBudget() << endl << endl;
    os << team.rCourt << endl << endl;
    os << "Record: " << team.getNumberOfWins() << " - " << team.getNumberOfLoses() << endl << endl;
    os << "Players: " << endl;
    for (const auto& player : team.getPlayersConst()) {
        os << "#" << (player)->getPlayerNumber() << ", " << (player)->getName() << ", " << (player)->positionNames[player->getPlayerPosition()] << endl;
    }
    os << "----------------------------" << endl;
    return os;
}
