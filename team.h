#ifndef __TEAM_H
#define __TEAM_H

#include <iostream>
#include <string>
#include <list>  // Include list
#include "owner.h"
#include "player.h"
#include "court.h"
#include "Observer.h"
#include "Subject.h"

using namespace std;

class Team : public Observer
{
protected:
    string teamName; 
    Owner rOwner;
    Court rCourt;
    list<Player*> pAllPlayers; 
    int numberOfWins;
    int numberOfLoses;

public:
    Team();
    Team(const string& teamName, const Owner& owner, const Court& court, const list<Player*> players);

    void setName(const string& name);
    void setNumberOfWins(int wins);
    void setNumberOfLoses(int loses);
    void setOwner(const Owner& other);

    const string& getName() const;
    int getNumberOfWins() const;
    int getNumberOfLoses() const;
    int getNumberOfPlayers() const;
    const Court& getCourt() const;
    list<Player*> getPlayers();
    const list<Player*> getPlayersConst() const;

    void updateMatch(bool won) override;

    void incrementWins();
    void incrementLosses();
    Team& operator+(Player* other);
    friend ostream& operator<<(ostream& os, const Team& team);
};

#endif // __TEAM_H
