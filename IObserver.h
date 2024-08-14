#pragma once
#ifndef I_OBSERVER_H
#define I_OBSERVER_H

class IObserver {
public:
    virtual void update() = 0;  // Pure virtual function to be overridden by observers
    virtual ~IObserver() = default;
};

#endif // I_OBSERVER_H
