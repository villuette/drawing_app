#ifndef MYRECTANGLE_H
#define MYRECTANGLE_H

#include "myshape.h"

class MyRectangle : public MyShape
{
public:
    MyRectangle();
    void draw() override;
};

#endif // MYRECTANGLE_H
