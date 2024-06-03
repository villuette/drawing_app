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
    ShapesStorage *shapes;
    QRect calculateGeometry();
public:
     MyShapeGroup(ShapesStorage *contained_shapes, QWidget *parent = nullptr);
     void setPen(QPen pen) override;
     QPen getPen() override;
     void setSize(QSize size) override;
     void moveBy(QPoint vect) override;
     ShapesStorage* getShapes();
     void draw(QPainter*);
     void mouseReleaseEvent(QMouseEvent*) override;
     void mouseMoveEvent(QMouseEvent*) override;
     void mousePressEvent(QMouseEvent*) override;
     void setShapesSelected(MyShape*, QMouseEvent*);
     //recalc size on each operation
 };
#endif // MYSHAPEGROUP_H
