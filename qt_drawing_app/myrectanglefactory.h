#ifndef MYRECTANGLEFACTORY_H
#define MYRECTANGLEFACTORY_H

#include "shapefactory.h"
#include <myrectangle.h>

class MyRectangleFactory : public ShapeFactory
{
public:
    MyRectangleFactory();
    MyShape* createShape(QWidget* parent = nullptr);
};

#endif // MYRECTANGLEFACTORY_H
