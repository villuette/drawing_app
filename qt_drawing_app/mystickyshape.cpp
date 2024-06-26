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
        connect(sh, &MyShape::shapeSelected, this, &MyStickyShape::setShapesSelected);
        connect(sh, &MyShape::shapeMoved, this, &MyStickyShape::setShapesMoved);
        sh->show();
    }
}

MyStickyShape::~MyStickyShape(){
    for (MyShape* sh : *shapes){ //recursively unsubscribe inner sticky shapes
        if (auto shobs = dynamic_cast<IObserver*>(sh)){
            dr->removeObserver(shobs);
        }
    }
}

void MyStickyShape::setShapesMoved(MyShape *shape, QPoint vect){

    for (MyShape* sh : *shapes){
        for (MyShape* outer : *allShapes){
            if(outer != this && sh->geometry().intersects(outer->geometry())){
                allShapes->removeShape(outer);
                shapes->addShape(outer);
                connect(sh, &MyShape::shapeSelected, this, &MyStickyShape::setShapesSelected);
                return;
            }
        }
    }
    MyShapeGroup::setShapesMoved(shape, vect);
}

void MyStickyShape::setShapesSelected(){
    MyShapeGroup::setShapesSelected();
}
void MyStickyShape::updateState(ShapesStorage *allShapes, ShapesStorage *){ //should have access to remove itself from storage?
    this->allShapes = allShapes; //TODO copy state, not direct access
}
