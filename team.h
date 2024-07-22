#ifndef __TEAM_H
#define __TEAM_H

#include <iostream>
#include "owner.h"
#include "player.h"
#include "court.h"
using namespace std;

class Team
{
protected:
	char* teamName;
	Owner rOwner;
	Court rCourt;
	Player** pAllPlayers;
	int numberOfWins;
	int numberOfLoses;
	int numberOfPlayers;

public:
	Team();
	Team(const char* teamName, const Owner& owner, const Court& court, const Player* players=nullptr);
	Team(const Team& other);
	Team(Team&& other);
	~Team();

	void setName(const char* name);
	void setNumberOfWins(const int wins);
	void setNumberOfLoses(const int loses);
	void setNumberOfPlayers(const int newNumOfPlayers);
	void setOwner(const Owner& other);

	const char* getName() const;	   
	const int getNumberOfWins() const;
	const int getNumberOfLoses() const;
	const int getNumberOfPlayers() const;

	const Team& operator+(const Player& other); //Add Player
	Team& operator=(const Team& other);
	friend ostream& operator<<(ostream& os, const Team& team);
	void copyPlayers(const Player* players);
	
};

#endif // __TEAM_H