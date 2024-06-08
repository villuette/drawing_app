#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <shapesstorage.h>

class IObserver
{
public:
    virtual void updateState(ShapesStorage* allShapes, ShapesStorage* selected) = 0;
};

#endif // IOBSERVER_H
