#include "selectionarea.h"

SelectionArea::SelectionArea(ShapesStorage* sel_store, ShapesStorage* global_store, QWidget *parent)
    : QWidget{parent},
    storeof_selected(sel_store)
    //storeof_all(global_store)
{

}
void SelectionArea::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.setPen(QPen(Qt::red, 3));
    p.drawRect(rect().adjusted(1,1,-1,-1));
    p.setPen(QPen(Qt::green, 3));
    if (storeof_selected->length() > 1){
        for(MyShape* el : *storeof_selected){
            auto temprect = QRect(el->x()-x(), el->y()-y(), el->width(), el->height());
            p.drawRect(temprect);
        }
    }

    //setMouseTracking(true); // for working mousemove without button pressed
}


