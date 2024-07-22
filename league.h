#ifndef __LEAGUE_H
#define __LEAGUE_H

#include "district.h"
#include <iostream>
using namespace std;



class League
{
protected:
	static constexpr int NUMBER_OF_DISTRICTS = 2;
	District* pAllDistricts[NUMBER_OF_DISTRICTS];
	int currentNumberOfWorkers;
	int currentNumberOfOwners;
	Person** allWorkers;
	Owner** allOwners;

public:
	League();
	League(const League& other);
	League(League&& other);
	~League();

	District* getDistricts() const;
	const int getCurrentNumberOfWorkers() const;
	Person** getAllWorkers() const;
	Owner** getAllOwners() const;

	void setDistrict(const District& d);
	void setCurrentNumberOfWorkers(const int newNum);
	void addWorker(const Employee* e);
	void addOwner(const Owner* o);
	friend ostream& operator<<(ostream& os, const League& league);

};

#endif // LEAGUE