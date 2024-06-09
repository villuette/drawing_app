#ifndef MYSTICKYSHAPE_H
#define MYSTICKYSHAPE_H

#include <myshapegroup.h>
#include "myshapegroup.h"
#include <myrectangle.h>
#include <drawingarea.h>
class MyStickyShape : public MyShapeGroup, public virtual IObserver
{
    Q_OBJECT
    DrawingArea* dr; //i hope ill never use this
    ShapesStorage* others;
    ShapesStorage* allShapes;
public:
    MyStickyShape(QWidget* parent = nullptr);
    ~MyStickyShape();
    //void moveBy(QPoint) override;
    void updateState(ShapesStorage* allShapes, ShapesStorage* selected) override;
    void setShapesMoved(MyShape *shape, QPoint vect) override;
    void setShapesSelected() override;
};

#endif // MYSTICKYSHAPE_H
