#ifndef __LEAGUE_H
#define __LEAGUE_H

#include "district.h"
#include <iostream>
#include <list>  // Added list
using namespace std;

class League
{
protected:
    static constexpr int NUMBER_OF_DISTRICTS = 2;
    list<District> pAllDistricts;
    int currentNumberOfWorkers;
    int currentNumberOfOwners;
    int currentNumberOfPlayers;
    int currentNumberOfReferees;
    list<Person*> allWorkers;  
    list<Owner*> allOwners;  

public:
    League();

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
