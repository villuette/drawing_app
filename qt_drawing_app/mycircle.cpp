#include "mycircle.h"

MyCircle::MyCircle(QWidget* parent)
    : MyShape(parent)
{}
void MyCircle::draw(QPainter* p){
    p->drawEllipse(rect().adjusted(1,1,-1,-1));
}

