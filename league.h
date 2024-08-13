#ifndef __LEAGUE_H
#define __LEAGUE_H

#include "district.h"
#include <iostream>
#include <list>
using namespace std;

class League
{
protected:
    static League* instance;  // Static instance pointer
    list<District> pAllDistricts;
    int currentNumberOfWorkers;
    int currentNumberOfOwners;
    int currentNumberOfPlayers;
    int currentNumberOfReferees;
    list<Person*> allWorkers;
    list<Owner*> allOwners;

    League();  // Private constructor

public:
    // Public static method to get the single instance
    static League* getInstance();

    // Delete the copy constructor and assignment operator
    League(const League&) = delete;
    League& operator=(const League&) = delete;

    list<District>& getDistricts();
    int getCurrentNumberOfWorkers() const;
    int getCurrentNumberOfOwners() const;
    int getCurrentNumberOfPlayers() const;
    int getCurrentNumberOfReferees() const;
    list<Person*>& getAllWorkers();
    list<Owner*>& getAllOwners();

    void setDistrict(const District& d);
    void setCurrentNumberOfWorkers(const int newNum);
    void addWorker(const Employee* e);
    void addOwner(const Owner* o);
    friend ostream& operator<<(ostream& os, const League& league);
};

#endif // LEAGUE_H
