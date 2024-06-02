#include "drawingarea.h"

DrawingArea::DrawingArea(QWidget* parent)
    : QFrame(parent),
      currentSize(20,20),
      currentColor(Qt::black),
      selectionColor(Qt::green),
      store(new ShapesStorage()),
      selectedStore(new ShapesStorage()),
      selectionArea(selectedStore, store, this)
{
    this->setStyleSheet(QString("background: white"));
    selectionArea.hide();
}
void DrawingArea::BindStorage(ShapesStorage *_store){
    this->store = _store;
}
void DrawingArea::paintEvent(QPaintEvent *e){
}
void DrawingArea::mousePressEvent(QMouseEvent *e){}

void DrawingArea::mouseReleaseEvent(QMouseEvent *e){
    //selectionArea.hide(); //hides on click on outer space
    auto shape = createShape(e->pos());
    if (shape){
        store->addShape(shape);
    }
}
MyShape* DrawingArea::createShape(QPoint coords){

    auto shape = new MyCircle(this); //MUSTDO change to fabric
    shape->setSize(currentSize);
    shape->setPen(QPen(currentColor, 3)); //TODO make width setting with signal
    coords-=QPoint(shape->width()/2, shape->height()/2);
    shape->move(coords);
    shape->show();
    connect(shape, &MyShape::shapeSelected, this, &DrawingArea::setShapeSelected);
    return shape;
}
void DrawingArea::setCurrentColor(const QColor& color){
    this->currentColor = color;
}
void DrawingArea::setCurrentSize(QSize size){
    this->currentSize = size;
}
QColor DrawingArea::getSelectionColor(){
    return selectionColor;
}
QRect DrawingArea::calculateSelectionArea(){
    using namespace  std;
    int minX, minY, maxX, maxY;
    maxX = maxY = 0;
    minX = minY = INT_MAX;
    for(MyShape* el : *selectedStore){
        minX = min(minX, el->x());
        minY = min(minY, el->y());
        maxX = max(maxX, el->x()+el->width());
        maxY = max(maxY, el->y()+el->height());
    }
    return QRect(minX, minY, maxX-minX, maxY-minY);
}
void DrawingArea::setShapeSelected(MyShape *shape){
    //shape->setPen(QPen(selectionColor, shape->getPen().width()));
    if(selectedStore->contains(shape)){
        selectedStore->removeShape(shape);
    } else {
        selectedStore->addShape(shape);
    }

    selectionArea.setGeometry(calculateSelectionArea());
    if(selectionArea.isHidden()){
        selectionArea.show();
    }
    selectionArea.raise();
    selectionArea.repaint();

}
