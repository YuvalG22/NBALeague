// MatchSubject.cpp
#include "MatchSubject.h"

MatchSubject::MatchSubject(Team& homeTeam, Team& awayTeam, Refree& referee)
    : homeTeam(homeTeam), awayTeam(awayTeam), referee(referee) {
    // Notify observers upon creation
    notify();
}

void MatchSubject::attach(IObserver* observer) {
    observers.push_back(observer);
}

void MatchSubject::notify() {
    for (IObserver* observer : observers) {
        observer->update();
    }
}
