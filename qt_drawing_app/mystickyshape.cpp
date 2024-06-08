#include "mystickyshape.h"

MyStickyShape::MyStickyShape(QWidget* parent)
    :MyShapeGroup(new ShapesStorage(), parent)
{
    if(auto dr = qobject_cast<DrawingArea*>(parent)){
        qDebug() << "drawing area detected";
    }
    shapes->addShape(new MyCircle(parent));
    for (MyShape* sh : *shapes){
        sh->setPen(QPen(Qt::black, 3));
        qDebug() << "theres a shape";
        sh->show();

    }
}
void MyStickyShape::moveBy(QPoint _pos){
    for (MyShape* sh : *shapes){
        sh->moveBy(_pos);
        qDebug() << sh->pos();
    }
}
