#include "mycircle.h"

MyCircle::MyCircle(QWidget* parent)
    : MyShape(parent)
{

}
void MyCircle::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(Qt::blue);

    painter.drawEllipse(rect().adjusted(1,1,-1,-1));
    qDebug() << "painted";
}
