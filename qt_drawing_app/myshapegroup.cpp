#include "myshapegroup.h"

MyShapeGroup::MyShapeGroup(ShapesStorage *contained_shapes, QWidget *parent)
    :MyShape(parent),
    shapes(contained_shapes)
{
    setGeometry(calculateGeometry());
    qDebug() << "group geometry: " <<geometry();
    //connect(this, &MyShape::shapeSelected, this, &MyShapeGroup::setShapesSelected);
}
void MyShapeGroup::setPen(QPen pen){
    for(MyShape *el : *shapes){
        el->setPen(pen);
    }
}
QPen MyShapeGroup::getPen(){ //TODO head null-checks
    return shapes->begin().current->shape->getPen();
}
void MyShapeGroup::setSize(QSize size){
    for(MyShape *el : *shapes){
        el->setSize(size);
    }
}
void MyShapeGroup::moveBy(QPoint vect){
    for(MyShape *el : *shapes){
        el->moveBy(vect);
    }
}
ShapesStorage* MyShapeGroup::getShapes(){
    return shapes;

}
void MyShapeGroup::draw(QPainter *p){
    for(MyShape *el : *shapes){
        p->setPen(el->getPen());
        el->draw(p);
    }
}
QRect MyShapeGroup::calculateGeometry(){
    using namespace  std;
    int minX, minY, maxX, maxY;
    maxX = maxY = 0;
    minX = minY = INT_MAX;
    for(MyShape* el : *shapes){
        minX = min(minX, el->x());
        minY = min(minY, el->y());
        maxX = max(maxX, el->x()+el->width());
        maxY = max(maxY, el->y()+el->height());
    }
    return QRect(minX, minY, maxX-minX, maxY-minY);
}
void MyShapeGroup::mouseReleaseEvent(QMouseEvent*){

}
void MyShapeGroup::mouseMoveEvent(QMouseEvent*) {

}
void MyShapeGroup::mousePressEvent(QMouseEvent*) {
    qDebug() << "group touched";
}
void MyShapeGroup::setShapesSelected(MyShape* shape, QMouseEvent* e){
    qDebug() << "make all selected ...";
    for(MyShape* el : *shapes){
        if(el != shape)
            emit el->shapeSelected(el, e);
    }
}
