#include "selectionarea.h"

SelectionArea::SelectionArea(ShapesStorage* sel_store, QWidget *parent)
    : QWidget{parent},
    storeof_selected(sel_store)
{
}
void SelectionArea::paintEvent(QPaintEvent *){
    QPainter p(this);
    setGeometry(parentWidget()->rect()); //WONT work in constructor
    if (storeof_selected->length() > 1){
        p.setPen(QPen(Qt::red, 3));
        p.drawRect(calculateSelectionArea().adjusted(1,1,-1,-1));
    }
    p.setPen(QPen(Qt::green, 3));
    for(MyShape* el : *storeof_selected){
        el->drawSelection(&p);
    }
}
QRect SelectionArea::calculateSelectionArea(){
    using namespace  std;
    int minX, minY, maxX, maxY;
    maxX = maxY = 0;
    minX = minY = INT_MAX;
    for(MyShape* el : *storeof_selected){
        minX = min(minX, el->x());
        minY = min(minY, el->y());
        maxX = max(maxX, el->x()+el->width());
        maxY = max(maxY, el->y()+el->height());
    }
    return QRect(minX, minY, maxX-minX, maxY-minY);
}


