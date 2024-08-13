#include "match.h"

Match::Match()
    : refree(nullptr), teamA(nullptr), teamB(nullptr), resultA(0), resultB(0), court(nullptr), gameDate(Date()) {}

Match::Match(const Refree& ref, Team& teamA, Team& teamB, int resA, int resB, const Court& court, const Date gameDate)
    : refree(new Refree(ref)), teamA(&teamA), teamB(&teamB), resultA(resA), resultB(resB), court(new Court(court)), gameDate(gameDate) {}

const Refree& Match::getRefree() const {
    return *refree;
}

Team& Match::getTeamA() const {
    return *teamA;
}

Team& Match::getTeamB() const {
    return *teamB;
}

const Court& Match::getCourt() const {
    return *court;
}

int Match::getResultA() const {
    return resultA;
}

int Match::getResultB() const {
    return resultB;
}

const Date& Match::getDate() const {
    return gameDate;
}

void Match::setRefree(const Refree& ref) {
    *refree = ref;
}

void Match::setTeamA(const Team& team) {
    *teamA = team;
}

void Match::setTeamB(const Team& team) {
    *teamB = team;
}

void Match::setDate(const Date& date) {
    gameDate = date;
}

void Match::setCourt(const Court& court) {
    this->court = new Court(court);
}

ostream& operator<<(ostream& os, const Match& match) {
    os << "Team A: " << match.getTeamA().getName() << " (" << match.getTeamA().getNumberOfWins() << " - " << match.getTeamA().getNumberOfLoses() << ") " << endl;
    os << "Team B: " << match.getTeamB().getName() << " (" << match.getTeamB().getNumberOfWins() << " - " << match.getTeamB().getNumberOfLoses() << ") " << endl;
    os << "Result: " << match.getTeamA().getName() << " " << match.getResultA() << " - " << match.getResultB() << " " << match.getTeamB().getName() << endl;
    os << "Court: " << match.getCourt() << endl;
    os << "Refree: " << match.getRefree().getName() << endl;
    os << "----------------------------" << endl;
    return os;
}
