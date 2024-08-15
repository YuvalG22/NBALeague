#ifndef __OBSERVER_H
#define __OBSERVER_H

class Observer {
public:
    virtual void updateMatch(bool won) = 0;
    virtual ~Observer() = default;
};

#endif // __OBSERVER_H
