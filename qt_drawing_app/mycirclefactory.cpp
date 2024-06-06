#include "mycirclefactory.h"

MyCircleFactory::MyCircleFactory()
{
}
MyShape* MyCircleFactory::createShape(){
    return new MyCircle();
}
