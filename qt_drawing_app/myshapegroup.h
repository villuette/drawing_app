#ifndef MYSHAPEGROUP_H
#define MYSHAPEGROUP_H

#include "myshape.h"
#include <QWidget>
#include <shapesstorage.h>
#include <QPen>
#include <QException>
class MyShapeGroup : public MyShape
{
    Q_OBJECT
    void adaptSelectionBorder();
protected:
    ShapesStorage *shapes;
    ///void
public:
     MyShapeGroup(ShapesStorage *contained_shapes, QWidget *parent = nullptr);
     ~MyShapeGroup();
     void setPen(QPen pen) override;
     QPen getPen() override;
     void setSize(QSize size) override;
     void moveBy(QPoint vect) override;
     ShapesStorage* getShapes();
     void draw(QPainter*) override;
     virtual void setShapesSelected();
     virtual void setShapesMoved(MyShape* shape, QPoint vect);
     void drawSelection(QPainter* p) override;
     QString getType() override;
     QString getShapeDataStringified() override;
 };
#endif // MYSHAPEGROUP_H
