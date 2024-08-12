#ifndef __TEAM_H
#define __TEAM_H

#include <iostream>
#include <string>
#include <list>  // Include list
#include "owner.h"
#include "player.h"
#include "court.h"

using namespace std;

class Team
{
protected:
    string teamName;  // Changed from char* to std::string
    Owner rOwner;
    Court rCourt;
    list<Player> pAllPlayers;  // Changed from Player** to std::list<Player>
    int numberOfWins;
    int numberOfLoses;

public:
    Team();
    Team(const string& teamName, const Owner& owner, const Court& court, const list<Player>& players);
    Team(const Team& other);
    Team(Team&& other);  
    ~Team();

    void setName(const string& name);
    void setNumberOfWins(int wins);
    void setNumberOfLoses(int loses);
    void setOwner(const Owner& other);

    const string& getName() const;
    int getNumberOfWins() const;
    int getNumberOfLoses() const;
    int getNumberOfPlayers() const;
    const Court& getCourt() const;
    const list<Player>& getPlayers() const;  // Added getter for players

    void incrementWins();
    void incrementLosses();
    const Team& operator+(const Player& other);  // Add Player
    Team& operator=(const Team& other);
    friend ostream& operator<<(ostream& os, const Team& team);
};

#endif // __TEAM_H
