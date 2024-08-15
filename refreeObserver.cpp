#include "RefreeObserver.h"

RefreeObserver::RefreeObserver(Refree& refree) : refree(refree) {}

void RefreeObserver::update() {
    refree.setNumberOfMatches(refree.getNumberOfMatches() + 1);  // Increment match count
}
