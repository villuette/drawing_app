#include "myshape.h"

MyShape::MyShape(QWidget *parent)
    : QWidget{parent}
{
    painter = new QPainter();
}

void MyShape::paintEvent(QPaintEvent *){
    painter->begin(this);
    draw();
    painter->end();
}
void MyShape::draw(){
}
