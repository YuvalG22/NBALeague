#include "PlayerObserver.h"

PlayerObserver::PlayerObserver(Player& player) : player(player) {}

void PlayerObserver::update() {
    // Increment the player's match count or perform other update actions
    player.setPlayerMatches(player.getPlayerMatches() + 1);
}
