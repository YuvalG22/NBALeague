#ifndef PLAYER_OBSERVER_H
#define PLAYER_OBSERVER_H

#include "IObserver.h"
#include "Player.h"

class PlayerObserver : public IObserver {
private:
    Player& player;  // Now this is a non-const reference

public:
    PlayerObserver(Player& player);
    virtual void update() override;
};

#endif // PLAYER_OBSERVER_H
