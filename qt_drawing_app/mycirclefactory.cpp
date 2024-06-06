#include "mycirclefactory.h"

MyCircleFactory::MyCircleFactory()
{
}
MyShape* MyCircleFactory::createShape(QWidget* parent){
    return new MyCircle(parent);
}
