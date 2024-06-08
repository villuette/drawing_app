#ifndef MYSTICKYFACTORY_H
#define MYSTICKYFACTORY_H

#include "shapefactory.h"
#include <mystickyshape.h>
class MyStickyFactory : public ShapeFactory
{
public:
    MyStickyFactory();
    MyShape* createShape(QWidget *parent) override;
};

#endif // MYSTICKYFACTORY_H
