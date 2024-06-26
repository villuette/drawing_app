#include "drawingarea.h"

DrawingArea::DrawingArea(QWidget* parent)
    : QFrame(parent),
      currentSize(20,20),
      currentColor(Qt::black),
      store(new ShapesStorage()),
      selectedStore(new ShapesStorage()),
      selectionArea(selectedStore, this)
{
    this->setStyleSheet(QString("background: white"));
    this->factory = new MyCircleFactory();
    selectionArea.hide();
}
void DrawingArea::bindStorage(ShapesStorage *_store){
    delete store;
    selectedStore->purge();
    store = _store;
    notifyObservers();
}
ShapesStorage* DrawingArea::getStorage(){
    return store;
}

void DrawingArea::addObserver(IObserver* obs){
    observers.push_back(obs);
}
void DrawingArea::removeObserver(IObserver *iobs){
     observers.erase(std::find(observers.begin(),observers.end(),iobs));
}
void DrawingArea::notifyObservers(){
    for(auto obs : observers){
        qDebug() << obs;
        obs->updateState(store, selectedStore);
    }
}

void DrawingArea::updateState(ShapesStorage *, ShapesStorage *withSelectedShape){
    setShapeSelected(withSelectedShape->begin().current->shape);
    setFocus();
}

void DrawingArea::enterEvent(QEnterEvent *event){
    setFocus();
}
void DrawingArea::mouseReleaseEvent(QMouseEvent *e){
    auto shape = createShape(e->pos());
    if (shape){
        store->addShape(shape);
        setShapeSelected(shape);
    }
}
void DrawingArea::drawSelectionArea(){
    if(selectionArea.isHidden()){
        selectionArea.show();
    }
    selectionArea.repaint();
}
MyShape* DrawingArea::createShape(QPoint coords){
    auto shape = factory->createShape(this);
    shape->setSize(currentSize);
    shape->setPen(QPen(currentColor, 3)); //TODO make width setting with signal
    coords-=QPoint(shape->width()/2, shape->height()/2);
    shape->moveBy(coords);
    shape->show();
    connect(shape, &MyShape::shapeSelected, this, &DrawingArea::setShapeSelected);
    connect(shape, &MyShape::shapeMoved, this, &DrawingArea::moveSelectedShapes);
    return shape;

}
void DrawingArea::setCurrentColor(const QColor& color){
    this->currentColor = color;
    for (MyShape* el : *selectedStore){
        el->setPen(QPen(color, el->getPen().width()));
    }
}
void DrawingArea::setCurrentSize(QSize size){
    this->currentSize = size;
    for (MyShape* el : *selectedStore){
        el->setSize(size);
    }
    drawSelectionArea();
    repaint();
}

void DrawingArea::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Control){
        ctrlPressed = true;
    }
}
void DrawingArea::keyReleaseEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Control){
        ctrlPressed = false;
    }
    if(event->key() == Qt::Key_Delete){
        for (MyShape* shape : *selectedStore){
            store->removeShape(shape);
            if(auto shape_obs = dynamic_cast<IObserver*>(shape)){
                removeObserver(shape_obs);
            }
            delete shape;
        }
        selectedStore->purge();
        notifyObservers();
        repaint();
    }

    if (event->key() == Qt::Key_G && (event->modifiers() & Qt::ShiftModifier)) {
        ungroup();
    } else if (event->key() == Qt::Key_G) {
        group();
    }
}
void DrawingArea::setShapeSelected(MyShape *shape){
    if (!ctrlPressed){
        selectedStore->purge();
    }
    if(selectedStore->contains(shape)){
        selectedStore->removeShape(shape);
        drawSelectionArea();
        notifyObservers();
        return;
    }
    selectedStore->addShape(shape);
    notifyObservers();
    drawSelectionArea();
}
void DrawingArea::moveSelectedShapes(MyShape *shape, QPoint vect){
    if(!selectedStore->contains(shape)){
        setShapeSelected(shape);
    }
    for(MyShape* el : *selectedStore){
        el->moveBy(vect);
    }
    drawSelectionArea();
    if (checkAreaLeaving()){ //TODO Glide-effect on crossing frame
        for(MyShape* el : *selectedStore){
            el->moveBy(-vect);
        }
    }
    drawSelectionArea();
}
bool DrawingArea::checkAreaLeaving(){
    for (MyShape* el : *selectedStore){
        if (!rect().contains(el->geometry())){
            return true;
        }
    }
    return false;
}
void DrawingArea::group(){ //TODO recursive grouping checks
    MyShapeGroup* mygroup = new MyShapeGroup(selectedStore, this);
    for (MyShape* sh : *selectedStore) {
        store->removeShape(sh);
        disconnect(sh, &MyShape::shapeMoved, this, &DrawingArea::moveSelectedShapes);
        disconnect(sh, &MyShape::shapeSelected, this, &DrawingArea::setShapeSelected);
    }
    store->addShape(mygroup);
    connect(mygroup, &MyShapeGroup::shapeSelected, this, &DrawingArea::setShapeSelected);
    connect(mygroup, &MyShapeGroup::shapeMoved, this, &DrawingArea::moveSelectedShapes);
    setShapeSelected(mygroup);
}
void DrawingArea::ungroup(){
    for (MyShape* sh : *selectedStore) {
        MyShapeGroup* mygroup = qobject_cast<MyShapeGroup*>(sh);
        if(!mygroup){
            continue;
        }
        for(MyShape* contained_shape : *mygroup->getShapes()){
            store->addShape(contained_shape);
            connect(contained_shape, &MyShape::shapeMoved, this, &DrawingArea::moveSelectedShapes);
            connect(contained_shape, &MyShape::shapeSelected, this, &DrawingArea::setShapeSelected);
        }
        selectedStore->removeShape(mygroup);
        store->removeShape(mygroup);

        mygroup->getShapes()->purge();
        delete mygroup;
    }
    repaint();
    notifyObservers();
}
void DrawingArea::setActiveFactory(ShapeFactory *f){
    factory = f;
}
