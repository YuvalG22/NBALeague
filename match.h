#ifndef __MATCH_H
#define __MATCH_H

#include <iostream>
#include "refree.h"
#include "date.h"
#include "team.h"

using namespace std;

class Match
{
protected:
	Refree* refree;
	Team* teamA;
	Team* teamB;
	int resultA;
	int resultB;
	Court* court;
	Date gameDate;

public:
	Match();
	Match(const Refree& ref, const Team& teamA, const Team& teamB, const Court& court, const Date gameDate);	
	~Match();

	const Refree& getRefree() const;
	const Team& getTeamA() const;
	const Team& getTeamB() const;
	const Court& getCourt() const;
	int getResultA() const;
	int getResultB() const;
	const Date& getDate() const;

	void	setRefree(const Refree& ref);
	void	setTeamA(const Team& team);
	void	setTeamB(const Team& team);
	void	setDate(const Date& date);
	void	setCourt(const Court& court);

	friend ostream& operator<<(ostream& os, const Match& match);
	
};

Match* createMatch(const Team* teams, int numOfTeams);
void printTeams(const Team* teams);

#endif // __MATCH_H