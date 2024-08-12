#ifndef __TEAM_H
#define __TEAM_H

#include <iostream>
#include <string>
#include "owner.h"
#include "player.h"
#include "court.h"

using namespace std;

class Team
{
protected:
    string teamName;     // Changed from char* to std::string
    Owner rOwner;
    Court rCourt;
    Player** pAllPlayers;
    int numberOfWins;
    int numberOfLoses;
    int numberOfPlayers;

public:
    Team();
    Team(const string& teamName, const Owner& owner, const Court& court, Player** players, int numberOfPlayers);
    Team(const Team& other);
    Team(Team&& other) noexcept;   // Added noexcept for move constructor
    ~Team();

    void setName(const string& name);   
    void setNumberOfWins(int wins);
    void setNumberOfLoses(int loses);
    void setNumberOfPlayers(int newNumOfPlayers);
    void setOwner(const Owner& other);

    const string& getName() const;      
    int getNumberOfWins() const;
    int getNumberOfLoses() const;
    int getNumberOfPlayers() const;
    const Court& getCourt() const;      

    void incrementWins();
    void incrementLosses();
    const Team& operator+(const Player& other); // Add Player
    Team& operator=(const Team& other);
    friend ostream& operator<<(ostream& os, const Team& team);
    void copyPlayers(Player** players, int numberOfPlayers);
};

#endif // __TEAM_H
