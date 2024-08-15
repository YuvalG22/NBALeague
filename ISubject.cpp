#include "ISubject.h"

void ISubject::attach(IObserver* observer) {
    observers.push_back(observer);
}

void ISubject::detach(IObserver* observer) {
    observers.remove(observer);
}

void ISubject::notify() {
    for (IObserver* observer : observers) {
        observer->update();  // Notify each observer
    }
}
