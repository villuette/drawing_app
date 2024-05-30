#include "mycircle.h"

MyCircle::MyCircle(QWidget* parent)
    : MyShape(parent)
{

}
void MyCircle::draw(){
    //painter->begin(this);
    painter->setPen(Qt::blue);

    painter->drawEllipse(rect().adjusted(1,1,-1,-1));
    qDebug() << this << "painted";
    //painter->end();
}

