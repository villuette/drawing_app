#ifndef IOBSERVABLE_H
#define IOBSERVABLE_H

#include <QObject>
#include <iobserver.h>

class IObservable
{
public:
    virtual void addObserver(IObserver* obs) = 0;
    virtual void notifyObservers() = 0;
};

#endif // IOBSERVABLE_H
