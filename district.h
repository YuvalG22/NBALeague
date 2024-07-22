#ifndef __DISTRICT_H
#define __DISTRICT_H

#include <iostream>
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
	District(const char* area, const int currentNumberOfMatches, const int currentNumberOfTeams);
	const District& operator+(const Team& toAdd);
	const District& operator+(const Match& toAdd);

	const eAreaType getArea() const { return area; }
	const Team* getTeams() { return pAllTeams; }
	const Match* getMatches() { return pAllMatches; }
	void setArea(const eAreaType area);

	friend ostream& operator<<(ostream& os, const District& district);

protected:
	eAreaType area;
	Team pAllTeams[NUMBER_OF_TEAMS];
	Match pAllMatches[NUMBER_OF_GAMES_SEASON];
	int currentNumberOfTeams;
	int currentNumberOfMatches;
};

#endif // __DISTRICT_H