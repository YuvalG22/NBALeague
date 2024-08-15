#ifndef __PLAYER_H
#define __PLAYER_H

#include <iostream>
#include <string>
#include "employee.h"
#include "owner.h"
#include "Observer.h"

using namespace std;

class Player : public Employee, public Owner, public Observer
{
public:
    enum ePositionType { POINT_GUARD, SHOOTING_GUARD, SMALL_FORWARD, POWER_FORWARD, CENTER, eNumOfTypes };
    static const char* const positionNames[eNumOfTypes];


    Player(const Employee& e, int playerNumber, ePositionType position, int numberOfTitles, int numberOfMatches, bool isOwner);
    Player(const Employee& e, const Owner& o, int playerNumber, ePositionType position, int numberOfTitles, int numberOfMatches, bool isOwner);

    int getPlayerNumber() const;
    ePositionType getPlayerPosition() const;
    int getPlayerTitles() const;
    int getPlayerMatches() const;

    void setPlayerNumber(int number);
    void setPlayerPosition(ePositionType pos);
    void setPlayerTitles(int newTitles);
    void setPlayerMatches(int newMatches);

    void updateMatch(bool won) override;

    const Player& operator+(); // Add title
    virtual void toOs(ostream& os) const override;

    friend ostream& operator<<(ostream& os, const Player& player);

private:
    int playerNumber;
    ePositionType position;
    int numberOfTitles;
    int numberOfMatches;
    bool isOwner;
};

#endif // __PLAYER_H
