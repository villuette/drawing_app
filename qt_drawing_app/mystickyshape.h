#ifndef MYSTICKYSHAPE_H
#define MYSTICKYSHAPE_H

#include "myshapegroup.h"
#include <mycircle.h>
#include <drawingarea.h>
class MyStickyShape : public MyShapeGroup
{
    Q_OBJECT
public:
    MyStickyShape(QWidget* parent = nullptr);
    void moveBy(QPoint) override;
};

#endif // MYSTICKYSHAPE_H
