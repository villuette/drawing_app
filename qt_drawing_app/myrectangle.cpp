#include "myrectangle.h"

MyRectangle::MyRectangle(QWidget* parent)
    :MyShape(parent)
{

}
void MyRectangle::draw(QPainter* p){
    p->drawRect(rect().adjusted(1,1,-1,-1));
}
QString MyRectangle::getType(){
    return QString("MyRectangle");
}
