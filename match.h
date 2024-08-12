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
    Match(const Refree& ref, const Team& teamA, const Team& teamB, int resA, int resB, const Court& court, const Date gameDate);
    ~Match();

    const Refree& getRefree() const;
    Team& getTeamA() const;
    Team& getTeamB() const;
    const Court& getCourt() const;
    int getResultA() const;
    int getResultB() const;
    const Date& getDate() const;

    void setRefree(const Refree& ref);
    void setTeamA(const Team& team);
    void setTeamB(const Team& team);
    void setDate(const Date& date);
    void setCourt(const Court& court);

    friend ostream& operator<<(ostream& os, const Match& match);
};


#endif // __MATCH_H
