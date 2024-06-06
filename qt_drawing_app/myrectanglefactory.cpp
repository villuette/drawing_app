#include "myrectanglefactory.h"

MyRectangleFactory::MyRectangleFactory()
{

}
MyShape* MyRectangleFactory::createShape(QWidget* parent){
    return new MyRectangle(parent);
}
