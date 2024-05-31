#include "myshape.h"

MyShape::MyShape(QWidget *parent)
    : QWidget{parent}
{
    //usage: setGeometry(x(), y(), 20, 20);
}

void MyShape::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(this->pen);
    draw(&painter);
    //setGeometry();
}
void MyShape::draw(QPainter *p){

}
void MyShape::setPen(QPen _pen){
    pen = _pen;
    //pen.setWidth(3);
    //TODO make normal pen width setting
}
void MyShape::setSize(QSize size){
    setGeometry(x(), y(), size.width(), size.height());
}
