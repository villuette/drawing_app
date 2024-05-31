#ifndef MYRECTANGLE_H
#define MYRECTANGLE_H

#include "myshape.h"

class MyRectangle : public MyShape
{
public:
    MyRectangle();
    void draw(QPainter* p) override;
};

#endif // MYRECTANGLE_H
