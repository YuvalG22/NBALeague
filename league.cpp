#include "league.h"

League* League::instance = nullptr;

League::League()
    : currentNumberOfWorkers(0), currentNumberOfOwners(0), currentNumberOfPlayers(0), currentNumberOfReferees(0) {

    // Initialize the list of districts with EAST and WEST
    pAllDistricts.push_back(District("East", 0, 0));  // Add EAST district
    pAllDistricts.push_back(District("West", 0, 0));  // Add WEST district
}

League& League::getInstance() {
    static League instance;
    return instance;
}

list<District>& League::getDistricts() {
    return pAllDistricts;
}

int League::getCurrentNumberOfWorkers() const {
    return currentNumberOfWorkers;
}

int League::getCurrentNumberOfOwners() const {
    return currentNumberOfOwners;
}

int League::getCurrentNumberOfPlayers() const {
    return currentNumberOfPlayers;
}

int League::getCurrentNumberOfReferees() const {
    return currentNumberOfReferees;
}

list<Person*>& League::getAllWorkers() {
    return allWorkers;
}

list<Owner*>& League::getAllOwners() {
    return allOwners;
}

void League::setDistrict(const District& d) {
    pAllDistricts.push_back(d);
}

void League::setCurrentNumberOfWorkers(const int newNum) {
    currentNumberOfWorkers = newNum;
}

void League::addWorker(const Employee* e) {
    if (const Player* p = dynamic_cast<const Player*>(e)) {
        allWorkers.push_back(new Player(*p));
        currentNumberOfPlayers++;
    }
    else if (const Refree* r = dynamic_cast<const Refree*>(e)) {
        allWorkers.push_back(new Refree(*r));
        currentNumberOfReferees++;
    }
}

void League::addOwner(const Owner* o) {
    allOwners.push_back(const_cast<Owner*>(o));
    currentNumberOfOwners++;
}

ostream& operator<<(ostream& os, const League& league) {
    os << "League Information: " << endl;
    os << "Number of Workers: " << league.getCurrentNumberOfWorkers() << endl;
    os << "Number of Owners: " << league.getCurrentNumberOfOwners() << endl;
    os << "Number of Players: " << league.getCurrentNumberOfPlayers() << endl;
    os << "Number of Referees: " << league.getCurrentNumberOfReferees() << endl;
    return os;
}
