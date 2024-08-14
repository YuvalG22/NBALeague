#ifndef __DISTRICT_H
#define __DISTRICT_H

#include <iostream>
#include <string>
#include <list>
#include "LinkedList.h"
#include "team.h"
#include "match.h"

using namespace std;

class District
{
public:
    static constexpr int NUMBER_OF_TEAMS = 12;
    static constexpr int NUMBER_OF_GAMES_SEASON = 72;
    enum eAreaType { EAST, WEST, eNumOfTypes };
    static const std::string areas[eNumOfTypes];

    District();
    District(const std::string& area, int currentNumberOfMatches, int currentNumberOfTeams);
    const District& operator+(const Team& toAdd);
    const District& operator+(const Match& toAdd);

    eAreaType getArea() const { return area; }
    list<Team>& getTeams() { return pAllTeams; }
    LinkedList<Match>* getMatches() { return &pAllMatches; }
    const std::list<Team>& getTeams() const;
    void setArea(eAreaType area);
    int getNumOfTeams() const;
    int getNumOfMatches() const;

protected:
    eAreaType area;
    list<Team> pAllTeams;
    LinkedList<Match> pAllMatches;
    int currentNumberOfTeams;
    int currentNumberOfMatches;
};

#endif // __DISTRICT_H
