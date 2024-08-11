#include <iostream>
#include "league.h"

League::League() : currentNumberOfWorkers(0), currentNumberOfOwners(0), currentNumberOfReferees(0), currentNumberOfPlayers(0) {

    pAllDistricts[0] = new District("East", 0, 0);
    pAllDistricts[1] = new District("West", 0, 0);

    allWorkers = new Person * [currentNumberOfWorkers];
    allOwners = new Owner * [currentNumberOfOwners];
}

League::League(const League& other) {
    currentNumberOfWorkers = other.currentNumberOfWorkers;
    currentNumberOfOwners = other.currentNumberOfOwners;

    for (int i = 0; i < NUMBER_OF_DISTRICTS; ++i) {
        pAllDistricts[i] = new District(*(other.pAllDistricts[i]));
    }

    allWorkers = new Person * [currentNumberOfWorkers];
    for (int i = 0; i < currentNumberOfWorkers; ++i) {
        allWorkers[i] = other.allWorkers[i];
    }

    allOwners = new Owner * [currentNumberOfOwners];
    for (int i = 0; i < currentNumberOfOwners; ++i) {
        allOwners[i] = new Owner(*(other.allOwners[i]));
    }
}

League::League(League&& other) {
    currentNumberOfWorkers = other.currentNumberOfWorkers;
    currentNumberOfOwners = other.currentNumberOfOwners;

    for (int i = 0; i < NUMBER_OF_DISTRICTS; ++i) {
        pAllDistricts[i] = other.pAllDistricts[i];
        other.pAllDistricts[i] = nullptr;
    }

    allWorkers = other.allWorkers;
    other.allWorkers = nullptr;

    allOwners = other.allOwners;
    other.allOwners = nullptr;
}

League::~League() {
    for (int i = 0; i < NUMBER_OF_DISTRICTS; ++i) {
        delete pAllDistricts[i];
    }
    delete[] allWorkers;
    delete[] allOwners;
}

District** League::getDistricts() {
    return pAllDistricts;
}

const int League::getCurrentNumberOfWorkers() const{
    return currentNumberOfWorkers;
}

const int League::getCurrentNumberOfOwners() const {
    return currentNumberOfOwners;
}

const int League::getCurrentNumberOfPlayers() const {
    return currentNumberOfPlayers;
}

const int League::getCurrentNumberOfReferees() const {
    return currentNumberOfReferees;
}

Person** League::getAllWorkers() const{
    return allWorkers;
}

Owner** League::getAllOwners() const{
    return allOwners;
}

// Setters
void League::setDistrict(const District& d) {

}

void League::setCurrentNumberOfWorkers(const int newNum) {
    currentNumberOfWorkers = newNum;
}

void League::addWorker(const Employee* e) {
    Person** newWorkers = new Person * [currentNumberOfWorkers + 1];
    for (int i = 0; i < currentNumberOfWorkers; ++i) {
        newWorkers[i] = allWorkers[i];
    }
    if (const Player* p = dynamic_cast<const Player*>(e)) {
        newWorkers[currentNumberOfWorkers] = new Player(*p);
        currentNumberOfPlayers++;
    }
    if (const Refree* r = dynamic_cast<const Refree*>(e)) {
        newWorkers[currentNumberOfWorkers] = new Refree(*r);
        currentNumberOfReferees++;
    }
    delete[] allWorkers;
    allWorkers = newWorkers;
    currentNumberOfWorkers++;
}

void League::addOwner(const Owner* o) {
    Owner** newOwners = new Owner * [currentNumberOfOwners + 1];
    for (int i = 0; i < currentNumberOfOwners; ++i) {
        newOwners[i] = allOwners[i];
    }
    newOwners[currentNumberOfOwners] = new Owner(*o);
    delete[] allOwners; 
    allOwners = newOwners;
    currentNumberOfOwners++;
}

ostream& operator<<(ostream& os, const League& league) {
    os << "League Details:\n";
    os << "Number of Districts: " << League::NUMBER_OF_DISTRICTS << endl;
    os << "Current Number of Workers: " << league.currentNumberOfWorkers << endl;
    os << "Current Number of Owners: " << league.currentNumberOfOwners << endl;

    os << "Districts:\n";
    for (int i = 0; i < League::NUMBER_OF_DISTRICTS; ++i) {
        os << "District " << i + 1 << ":\n";
        if (league.pAllDistricts[i]) {
            os << *(league.pAllDistricts[i]) << endl;
        }
        else {
            os << "No district information available.\n";
        }
    }

    os << "Workers:\n";
    for (int i = 0; i < league.currentNumberOfWorkers; ++i) {
        os << *(league.allWorkers[i]) << endl;
    }

    os << "Owners:\n";
    for (int i = 0; i < league.currentNumberOfOwners; ++i) {
        os << *(league.allOwners[i]) << endl;
    }

    return os;
}