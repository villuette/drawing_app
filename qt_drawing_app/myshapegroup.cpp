#include "myshapegroup.h"

MyShapeGroup::MyShapeGroup(ShapesStorage *contained_shapes, QWidget *parent)
    :MyShape(parent)
{
    shapes = new ShapesStorage();
    for (MyShape* sh : *contained_shapes) {
        shapes->addShape(sh);
        connect(sh, &MyShape::shapeSelected, this, &MyShapeGroup::setShapesSelected);
        connect(sh, &MyShape::shapeMoved, this, &MyShapeGroup::setShapesMoved);
    }
    adaptSelectionBorder();
}
MyShapeGroup::~MyShapeGroup(){
    for (MyShape* sh : *shapes) {
        disconnect(sh, &MyShape::shapeSelected, this, &MyShapeGroup::setShapesSelected);
        disconnect(sh, &MyShape::shapeMoved, this, &MyShapeGroup::setShapesMoved);
        shapes->removeShape(sh);
        delete sh;
    }
    shapes->purge(); //standart destructor must not delete contained shapes
    delete shapes;
}
QString MyShapeGroup::getType(){
    return QString("MyShapeGroup");
}
QString MyShapeGroup::getShapeDataStringified(){
    QString data;
    data.append(this->getType() + "\n");
    data.append(QString::number(shapes->length()) + "\n");
    for (MyShape* sh : *shapes){
        data.append(sh->getShapeDataStringified());
    }
    return data;
}
void MyShapeGroup::drawSelection(QPainter *p){
    auto default_pen = p->pen();
    p->setPen(QPen(Qt::blue, 3));
    p->drawRect(geometry());
    p->setPen(default_pen);
    for(MyShape* sh : *shapes){
        sh->drawSelection(p);
    }
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
    adaptSelectionBorder();
}
ShapesStorage* MyShapeGroup::getShapes(){
    return shapes;

}
void MyShapeGroup::draw(QPainter *p){
    for(MyShape *el : *shapes){
        el->draw(p);
    }
}
void MyShapeGroup::adaptSelectionBorder(){
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
    setGeometry(QRect(minX, minY, maxX-minX, maxY-minY));
}

void MyShapeGroup::setShapesSelected(){
    adaptSelectionBorder();
    emit shapeSelected(this);
}
void MyShapeGroup::setShapesMoved(MyShape* shape, QPoint vect){
    emit shapeMoved(this, vect);
}
