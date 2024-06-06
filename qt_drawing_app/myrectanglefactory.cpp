#include "myrectanglefactory.h"

MyRectangleFactory::MyRectangleFactory()
{

}
MyShape* MyRectangleFactory::createShape(){
    return new MyRectangle();
}
