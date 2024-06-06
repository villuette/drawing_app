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
void MyShape::mouseReleaseEvent(QMouseEvent *e){
    if(!wasMoved)
        emit shapeSelected(this);
}
void MyShape::mouseMoveEvent(QMouseEvent *e){
    auto vect = e->pos() - startMovePosition;
    wasMoved = true;
    emit shapeMoved(this, vect);
}
void MyShape::moveBy(QPoint vect){
    move(pos() + vect);
}
void MyShape::drawSelection(QPainter *p){
    p->drawRect(geometry());
}
void MyShape::mousePressEvent(QMouseEvent *e){
    startMovePosition = e->pos();
    wasMoved = false;
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
void MyShape::setStartMovePosition(QPoint p){
    startMovePosition = p;
}
QPoint MyShape::getStartMovePosition(){
    return startMovePosition;
}
