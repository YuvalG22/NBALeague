#ifndef __PLAYER_H
#define __PLAYER_H

#include <iostream>
#include "employee.h"
#include "owner.h"

using namespace std;

class Player : public Employee, public Owner
{

public:
	enum  ePositionType {POINT_GUARD, SHOOTING_GUARD, SMALL_FORWARD, POWER_FORWARD, CENTER, eNumOfTypes};
	static constexpr const char* positionNames[eNumOfTypes] = {"Point Guard", "Shooting Guard", "Small Forward", "Power Forward", "Center"};

	Player(const Employee& e, const int playerNumber, ePositionType position, const int numberOfTitles, const int numberOfMatches, bool isOwner);
	Player(const Employee& e, const Owner& o, const int playerNumber, ePositionType position, const int numberOfTitles, const int numberOfMatches, bool isOwner);// if the player is also an owner

	const int getPlayerNumber() const;
	const ePositionType getPlayerPosition() const;
	const int getPlayerTitles() const;
	const int getPlayerMatches() const;

	void setPlayerNumber(const int number);
	void setPlayerPosition(const ePositionType pos);
	void setPlayerTitles(const int newTitles);
	void setPlayerMatches(const int newMatches);

	const Player& operator+(); // Add title
	virtual void toOs(ostream& os) const override;
	friend ostream& operator<<(ostream& os, const Player& player);

protected:
	int playerNumber;
	ePositionType position;
	int numberOfTitles;
	int numberOfMatches;
	bool isOwner;
};

#endif // __PLAYER_H