#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QFrame>
#include <QWidget>
#include <shapesstorage.h>
#include <QMouseEvent>
#include <mycircle.h>
#include <QLayout>
#include <selectionarea.h>
#include <climits>
#include <QKeyEvent>
#include <myshapegroup.h>
#include <shapefactory.h>
#include <mycirclefactory.h>
#include <iobservable.h>
class DrawingArea : public QFrame, public IObservable
{
    Q_OBJECT
    bool ctrlPressed = false;
    QColor currentColor;
    QSize currentSize;
    std::vector<IObserver*> observers;
    ShapesStorage* store; //destroys all contained shapes on program exit
    ShapesStorage* selectedStore; //contains only selected shapes
    ShapeFactory* factory; //as initial state
    SelectionArea selectionArea;

    void group();
    void ungroup();
    void drawSelectionArea();
    bool checkAreaLeaving();

public:
    DrawingArea(QWidget* parent = nullptr);
    void bindStorage(ShapesStorage* _store); //accessed for loading and saving files
    ShapesStorage* getStorage();
    void keyReleaseEvent(QKeyEvent *event) override;
    void mouseReleaseEvent(QMouseEvent* e) override;
    void keyPressEvent(QKeyEvent *event) override;
    void enterEvent(QEnterEvent *event) override;
    MyShape* createShape(QPoint coords); //accessed for loading and saving files

    //IObservable:
    void addObserver(IObserver*) override;
    void notifyObservers() override;

public slots:
    void setCurrentColor(const QColor &color);
    void setCurrentSize(QSize size);
    void setShapeSelected(MyShape* shape);
    void moveSelectedShapes(MyShape*, QPoint);
    void setActiveFactory(ShapeFactory* f);
};

#endif // DRAWINGAREA_H
