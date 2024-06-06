#ifndef MYRECTANGLE_H
#define MYRECTANGLE_H

#include "myshape.h"

class MyRectangle : public MyShape
{
public:
    MyRectangle(QWidget* parent = nullptr);
    void draw(QPainter* p) override;
};

#endif // MYRECTANGLE_H
