#ifndef MYRECTANGLEFACTORY_H
#define MYRECTANGLEFACTORY_H

#include "shapefactory.h"
#include <myrectangle.h>

class MyRectangleFactory : public ShapeFactory
{
public:
    MyRectangleFactory();
    MyShape* createShape();
};

#endif // MYRECTANGLEFACTORY_H
