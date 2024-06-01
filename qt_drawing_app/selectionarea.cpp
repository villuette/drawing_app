#include "selectionarea.h"

SelectionArea::SelectionArea(QWidget *parent)
    : QWidget{parent}
{

}
void SelectionArea::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.setPen(QPen(Qt::red, 3));
    p.drawRect(rect().adjusted(1,1,-1,-1));
}
