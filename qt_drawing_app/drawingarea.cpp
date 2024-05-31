#include "drawingarea.h"

DrawingArea::DrawingArea(QWidget* parent)
    : QFrame(parent),
      currentSize(20,20),
      currentColor(Qt::black)
{
    BindStorage(new ShapesStorage());
    this->setStyleSheet(QString("background: white"));

}
void DrawingArea::BindStorage(ShapesStorage *_store){
    this->store = _store;
}
void DrawingArea::paintEvent(QPaintEvent *e){

}
void DrawingArea::mousePressEvent(QMouseEvent *e){
    //qDebug() << e->pos()+QPoint(500,500);

}
void DrawingArea::mouseReleaseEvent(QMouseEvent *e){
    auto shape = createShape(e->pos());
    if (shape){
        store->addShape(shape);
    }
    //HONORABLE MENTION REPAINT
}
MyShape* DrawingArea::createShape(QPoint coords){ //TODO set default values
    auto shape = new MyCircle(this);
    shape->setSize(currentSize);
    shape->setPen(QPen(currentColor, 3)); //TODO make width setting with signal
    coords-=QPoint(shape->width()/2, shape->height()/2);
    shape->move(coords);
    shape->show();
    return shape;
}
void DrawingArea::setCurrentColor(const QColor& color){
    this->currentColor = color;
}
void DrawingArea::setCurrentSize(QSize size){
    this->currentSize = size;
}
