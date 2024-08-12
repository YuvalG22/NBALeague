#ifndef __DISTRICT_H
#define __DISTRICT_H

#include <iostream>
#include "LinkedList.h"
#include "team.h"
#include "match.h"
using namespace std;

class District
{
public:
	static constexpr int NUMBER_OF_TEAMS = 12;
	static constexpr int NUMBER_OF_GAMES_SEASON = 72;
	enum  eAreaType { EAST, WEST, eNumOfTypes };
	const char* areas[eNumOfTypes] = { "East", "West"};
	District();
	District(const char* area, const int currentNumberOfMatches, const int currentNumberOfTeams);
	District(const District& other);
	const District& operator+(const Team& toAdd);
	const District& operator+(const Match& toAdd);

	const eAreaType getArea() const { return area; }
	Team* getTeams() { return pAllTeams; }
	LinkedList<Match>* getMatches() { return &pAllMatches; }
	void setArea(const eAreaType area);
	const int getNumOfTeams() const;
	const int getNumOfMatches() const;

protected:
	eAreaType area;
	Team pAllTeams[NUMBER_OF_TEAMS];
	LinkedList<Match> pAllMatches;
	int currentNumberOfTeams;
	int currentNumberOfMatches;
};

#endif // __DISTRICT_H