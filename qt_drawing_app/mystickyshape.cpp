#include "mystickyshape.h"

MyStickyShape::MyStickyShape(QWidget* parent)
    :MyShapeGroup(new ShapesStorage(), parent)
{
    others = new ShapesStorage();
    dr = qobject_cast<DrawingArea*>(parent);
    hide();
    setGeometry(0,0,0,0);
    shapes->addShape(new MyRectangle(parent)); //starting look of shape (maybe composition of shapes)
    for (MyShape* sh : *shapes){
        sh->setPen(QPen(Qt::red, 3));
        connect(sh, &MyShape::shapeSelected, this, &MyStickyShape::shapeSelected);
        connect(sh, &MyShape::shapeMoved, this, &MyStickyShape::setShapesMoved);
        sh->show();
    }
}

MyStickyShape::~MyStickyShape(){

}

void MyStickyShape::setShapesMoved(MyShape *shape, QPoint vect){

    for (MyShape* sh : *shapes){
        for (MyShape* outer : *allShapes){
            if(outer != this && sh->geometry().intersects(outer->geometry())){
                qDebug() << "INTERSECTION";
                allShapes->removeShape(outer);
                shapes->addShape(outer);

                return;
            }
        }
    }
    for (MyShape* sh : *shapes){
        qDebug() << "amount: " << shapes->length() << "pos: " <<  sh->pos();
    }
    MyShapeGroup::setShapesMoved(shape, vect);
}

void MyStickyShape::setShapesSelected(){
    MyShapeGroup::setShapesSelected();
}
void MyStickyShape::updateState(ShapesStorage *allShapes, ShapesStorage *){
//    others->purge();
//    for(MyShape* sh: *allShapes){
//        if (sh != this){
//            others->addShape(sh);
//            qDebug() << sh;
//        }
//    }
    this->allShapes = allShapes;
}
