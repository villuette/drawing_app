#include "drawingarea.h"

DrawingArea::DrawingArea(QWidget* parent)
    : QFrame(parent)
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
        qDebug() << shape <<"stored";
    }
    //HONORABLE MENTION REPAINT
}
MyShape* DrawingArea::createShape(QPoint coords){
    auto shape = new MyCircle(this);
    shape->move(coords); //TODO make shape centered on creation
    qDebug() << shape->size() << "|" << shape->pos() << "|" << shape->parent();
    shape->show();

    return shape;
}
