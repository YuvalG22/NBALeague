#include "PlayerObserver.h"

PlayerObserver::PlayerObserver(Player& player) : player(player) {}

void PlayerObserver::update() {
    std::cout << "Updating player: " << player.getName() << std::endl;
    std::cout << "Matches before update: " << player.getPlayerMatches() << std::endl;
    player.setPlayerMatches(player.getPlayerMatches() + 1);
    std::cout << "Matches after update: " << player.getPlayerMatches() << std::endl;
}

