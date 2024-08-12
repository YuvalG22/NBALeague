#include <iostream>
#include "district.h"

const std::string District::areas[District::eNumOfTypes] = { "East", "West" };

District::District() : area(EAST), currentNumberOfTeams(0), currentNumberOfMatches(0) {}

District::District(const std::string& areaName, int currentNumMatches, int currentNumTeams)
    : currentNumberOfTeams(currentNumTeams), currentNumberOfMatches(currentNumMatches) {
    if (areaName == "East")
        area = EAST;
    else if (areaName == "West")
        area = WEST;
    else
        area = EAST;  // Default to EAST if not recognized
}

District::District(const District& other)
    : area(other.area), currentNumberOfTeams(other.currentNumberOfTeams), currentNumberOfMatches(other.currentNumberOfMatches), pAllTeams(other.pAllTeams) {

    Node<Match>* current = other.pAllMatches.getHead();
    while (current) {
        pAllMatches.append(current->data);
        current = current->next;
    }
}

// Overloaded + operator to add a Team
const District& District::operator+(const Team& toAdd) {
    if (currentNumberOfTeams < NUMBER_OF_TEAMS) {
        pAllTeams.push_back(toAdd);
        currentNumberOfTeams++;
    }
    else {
        cout << "Cannot add more teams. Maximum number of teams reached." << endl;
    }
    return *this;
}

// Overloaded + operator to add a Match
const District& District::operator+(const Match& toAdd) {
    if (currentNumberOfMatches < NUMBER_OF_GAMES_SEASON) {
        pAllMatches.append(toAdd);
        currentNumberOfMatches++;
        if (toAdd.getResultA() > toAdd.getResultB()) {
            toAdd.getTeamA().incrementWins();
            toAdd.getTeamB().incrementLosses();
        }
        else {
            toAdd.getTeamA().incrementLosses();
            toAdd.getTeamB().incrementWins();
        }
    }
    else {
        cout << "Cannot add more matches. Maximum number of matches reached." << endl;
    }
    return *this;
}

// Setter for area
void District::setArea(eAreaType area) {
    this->area = area;
}

int District::getNumOfTeams() const {
    return currentNumberOfTeams;
}

int District::getNumOfMatches() const {
    return currentNumberOfMatches;
}
