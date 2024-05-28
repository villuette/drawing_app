#ifndef MYCIRCLE_H
#define MYCIRCLE_H

#include "myshape.h"
#include <QPaintEvent>
#include <QPainter>
class MyCircle : public MyShape
{
public:
    MyCircle(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent* e) override;
};

#endif // MYCIRCLE_H
