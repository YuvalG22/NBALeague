#include <iostream>
#include "district.h" 

District::District(const char* areaName, const int currentNumMatches, const int currentNumTeams)
    : currentNumberOfTeams(currentNumTeams), currentNumberOfMatches(currentNumMatches) {
    if (strcmp(areaName, "East") == 0)
        area = EAST;
    else if (strcmp(areaName, "West") == 0)
        area = WEST;
    else
        area = EAST;
}

// Overloaded + operator to add a Team
const District& District::operator+(const Team& toAdd) {
    if (currentNumberOfTeams < NUMBER_OF_TEAMS) {
        pAllTeams[currentNumberOfTeams++] = toAdd;
    }
    else {
        cout << "Cannot add more teams. Maximum number of teams reached." << endl;
    }
    return *this;
}

// Overloaded + operator to add a Match
const District& District::operator+(const Match& toAdd) {
    if (currentNumberOfMatches < NUMBER_OF_GAMES_SEASON) {
        pAllMatches[currentNumberOfMatches++] = toAdd;
    }
    else {
        cout << "Cannot add more matches. Maximum number of matches reached." << endl;
    }
    return *this;
}

// Setter for area
void District::setArea(const eAreaType area) {
    this->area = area;
}

// Overloaded << operator to print District details
ostream& operator<<(ostream& os, const District& district) {
    os << "District Area: " << district.areas[district.area] << endl;
    os << "Teams (" << district.currentNumberOfTeams << "):" << endl;
    for (int i = 0; i < district.currentNumberOfTeams; ++i) {
        os << district.pAllTeams[i] << endl;
    }
    os << "Matches (" << district.currentNumberOfMatches << "):" << endl;
    for (int i = 0; i < district.currentNumberOfMatches; ++i) {
        os << district.pAllMatches[i] << endl;
    }
    return os;
}