#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include <myshape.h>

class ShapeFactory
{
public:
    ShapeFactory();
    virtual MyShape* createShape(QWidget* parent = nullptr) = 0;
};

#endif // SHAPEFACTORY_H
