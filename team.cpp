#define _CRT_SECURE_NO_WARNINGS
#include "team.h"

Team::Team() : teamName(""), numberOfWins(0), numberOfLoses(0) {}

Team::Team(const string& teamName, const Owner& owner, const Court& court, const list<Player>& players)
    : teamName(teamName), rOwner(owner), rCourt(court), pAllPlayers(players), numberOfWins(0), numberOfLoses(0) {}

Team::Team(const Team& other)
    : teamName(other.teamName), rOwner(other.rOwner), rCourt(other.rCourt),
    pAllPlayers(other.pAllPlayers), numberOfWins(other.numberOfWins), numberOfLoses(other.numberOfLoses) {}

Team::Team(Team&& other) 
    : teamName(move(other.teamName)), rOwner(move(other.rOwner)), rCourt(move(other.rCourt)),
    pAllPlayers(move(other.pAllPlayers)), numberOfWins(other.numberOfWins), numberOfLoses(other.numberOfLoses) {
    other.numberOfWins = 0;
    other.numberOfLoses = 0;
}

Team::~Team() {
    // The list will automatically manage its memory, so no need for manual deletion
}

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

Team& Team::operator=(const Team& other) {
    if (this != &other) {
        teamName = other.teamName;
        rOwner = other.rOwner;
        rCourt = other.rCourt;
        pAllPlayers = other.pAllPlayers;
        numberOfWins = other.numberOfWins;
        numberOfLoses = other.numberOfLoses;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Team& team) {
    os << "Team Name: " << team.getName() << endl;
    os << "Owner: " << team.rOwner.getName() << endl;
    os << "Court: " << team.rCourt.getCourtName() << endl;
    os << "Number of Wins: " << team.getNumberOfWins() << endl;
    os << "Number of Loses: " << team.getNumberOfLoses() << endl;
    os << "Number of Players: " << team.getNumberOfPlayers() << endl;
    os << "Players: " << endl;
    for (const auto& player : team.getPlayers()) {
        os << player.getName() << endl;
    }
    return os;
}
