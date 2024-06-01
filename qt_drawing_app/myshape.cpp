#include "myshape.h"

MyShape::MyShape(QWidget *parent)
    : QWidget{parent}
{
}

void MyShape::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(this->pen);
    draw(&painter);
}
void MyShape::mouseReleaseEvent(QMouseEvent *){
    emit shapeSelected(this);
}
void MyShape::draw(QPainter *p){}
void MyShape::setPen(QPen _pen){
    pen = _pen;
}
QPen MyShape::getPen(){
    return pen;
}
void MyShape::setSize(QSize size){
    setGeometry(x(), y(), size.width(), size.height());
}

