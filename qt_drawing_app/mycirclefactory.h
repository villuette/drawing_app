#ifndef MYCIRCLEFACTORY_H
#define MYCIRCLEFACTORY_H

#include "shapefactory.h"
#include <mycircle.h>
class MyCircleFactory : public ShapeFactory
{
public:
    MyCircleFactory();
    MyShape* createShape(QWidget* parent = nullptr);
};

#endif // MYCIRCLEFACTORY_H
