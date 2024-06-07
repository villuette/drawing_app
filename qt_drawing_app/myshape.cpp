#include "myshape.h"

MyShape::MyShape(QWidget *parent)
    : QWidget{parent}
{
    //qDebug() << this->getType();
    pen.setWidth(3);
}

QString MyShape::getShapeDataStringified(){
    QString data;
    data.append(this->getType() + "\n");
    data.append(QString("location: { x: %1, y: %2 }\n").arg(x()).arg(y()));
    data.append(QString("size: { w: %1, h: %2 }\n").arg(width()).arg(height()));
    data.append(QString("color: %1\n").arg(getPen().color().name()));
    return data;
}
QString MyShape::getType(){
}
void MyShape::configureOnLoad(QPoint _pos, QSize _size, QPen _pen){
    setGeometry(QRect(_pos, _size));
    setPen(_pen);
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
