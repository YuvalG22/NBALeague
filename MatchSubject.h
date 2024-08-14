// MatchSubject.h
#ifndef MATCH_SUBJECT_H
#define MATCH_SUBJECT_H

#include <list>
#include "Team.h"
#include "Refree.h"
#include "IObserver.h"

class MatchSubject {
private:
    Team& homeTeam;
    Team& awayTeam;
    Refree& referee;
    std::list<IObserver*> observers;

public:
    MatchSubject(Team& homeTeam, Team& awayTeam, Refree& referee);

    void attach(IObserver* observer);
    void notify();

};

#endif // MATCH_SUBJECT_H
