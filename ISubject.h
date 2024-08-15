#ifndef ISUBJECT_H
#define ISUBJECT_H

#include "IObserver.h"
#include <list>

class ISubject {
private:
    std::list<IObserver*> observers;  // List of observers

public:
    virtual ~ISubject() {}
    void attach(IObserver* observer);
    void detach(IObserver* observer);
    void notify();  // Notify all attached observers
};

#endif // ISUBJECT_H
