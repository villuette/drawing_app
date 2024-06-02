#include "selectionarea.h"

SelectionArea::SelectionArea(ShapesStorage* sel_store, ShapesStorage* global_store, QWidget *parent)
    : QWidget{parent},
    storeof_selected(sel_store),
    storeof_all(global_store)
{

}
void SelectionArea::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.setPen(QPen(Qt::red, 3));
    p.drawRect(rect().adjusted(1,1,-1,-1));
    for(MyShape* el : *storeof_selected){
        auto temprect = QRect(el->x()-x(), el->y()-y(), el->width(), el->height());
        p.drawRect(temprect);
    }
    //setMouseTracking(true); // for working mousemove without button pressed
}

void SelectionArea::mouseReleaseEvent(QMouseEvent *event){
    //just send click to shapes behind
    for(MyShape* el : *storeof_all){
        if (el->geometry().contains(mapToParent(event->pos()))){
            el->mouseReleaseEvent(event);
        }
    }
}
void SelectionArea::mouseMoveEvent(QMouseEvent *event){
    auto realpos = mapToParent(event->pos()-press_location);
    move(realpos);
    for(MyShape* el : *storeof_selected){
        el->move(realpos + el->getStartMovePosition());
    }
}
void SelectionArea::mousePressEvent(QMouseEvent *event){
    press_location = event->pos();
    for(MyShape* el : *storeof_selected){
        el->setStartMovePosition(el->pos() - pos());
    }
    qDebug() << "pressed here";
}

