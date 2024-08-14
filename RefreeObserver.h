#ifndef REFREE_OBSERVER_H
#define REFREE_OBSERVER_H

#include "IObserver.h"
#include "Refree.h"

class RefreeObserver : public IObserver {
private:
    Refree& refree;  // Reference to the Refree being observed

public:
    RefreeObserver(Refree& refree);
    virtual void update() override;  // Override update method
};

#endif // REFREE_OBSERVER_H
