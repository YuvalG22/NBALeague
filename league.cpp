#include "league.h"

League::League()
    : currentNumberOfWorkers(0), currentNumberOfOwners(0), currentNumberOfPlayers(0), currentNumberOfReferees(0) {

    // Initialize the list of districts with EAST and WEST
    pAllDistricts.push_back(District("East", 0, 0));  // Add EAST district
    pAllDistricts.push_back(District("West", 0, 0));  // Add WEST district
}

League::League(const League& other)
    : pAllDistricts(other.pAllDistricts),
    currentNumberOfWorkers(other.currentNumberOfWorkers),
    currentNumberOfOwners(other.currentNumberOfOwners),
    currentNumberOfPlayers(other.currentNumberOfPlayers),
    currentNumberOfReferees(other.currentNumberOfReferees),
    allWorkers(other.allWorkers),
    allOwners(other.allOwners) {}

League::League(League&& other)
    : pAllDistricts(move(other.pAllDistricts)),
    currentNumberOfWorkers(other.currentNumberOfWorkers),
    currentNumberOfOwners(other.currentNumberOfOwners),
    currentNumberOfPlayers(other.currentNumberOfPlayers),
    currentNumberOfReferees(other.currentNumberOfReferees),
    allWorkers(move(other.allWorkers)),
    allOwners(move(other.allOwners)) {
    other.currentNumberOfWorkers = 0;
    other.currentNumberOfOwners = 0;
    other.currentNumberOfPlayers = 0;
    other.currentNumberOfReferees = 0;
}

League::~League() {
    for (Person* worker : allWorkers) {
        delete worker;
    }
    for (Owner* owner : allOwners) {
        delete owner;
    }
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
    allWorkers.push_back(const_cast<Employee*>(e));  // Add to the workers list
    currentNumberOfWorkers++;
}

void League::addOwner(const Owner* o) {
    allOwners.push_back(const_cast<Owner*>(o));  // Add to the owners list
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
