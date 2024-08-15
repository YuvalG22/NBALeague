#ifndef __SUBJECT_H
#define __SUBJECT_H

#include "observer.h"
#include <list>

class Subject {
private:
    std::list<Observer*> observers;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        observers.remove(observer);
    }

    void notifyMatch(bool won) {
        for (Observer* observer : observers) {
            observer->updateMatch(won);
        }
    }
};

#endif // __SUBJECT_H