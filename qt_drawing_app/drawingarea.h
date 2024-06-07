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
#include <mycirclefactory.h> //as initial state
class DrawingArea : public QFrame
{
    Q_OBJECT
    ShapesStorage* store; //destroys all contained shapes on program exit
    ShapesStorage* selectedStore; //contains only selected shapes
    ShapeFactory* factory; //or just make visitors
    QColor currentColor;
    QSize currentSize;
    QColor selectionColor;
    SelectionArea selectionArea;
    void group();
    void ungroup();
    QColor getSelectionColor();
    MyShape* createShape(QPoint coords);
    void drawSelectionArea();
    bool checkAreaLeaving();
    bool ctrlPressed = false;
    //TODO fabric
public:
    DrawingArea(QWidget* parent = nullptr);
    void bindStorage(ShapesStorage* _store); //accessed for loading and saving files
    ShapesStorage* getStorage();
    void keyReleaseEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent* e) override;
    void mouseReleaseEvent(QMouseEvent* e) override;
    void keyPressEvent(QKeyEvent *event) override;
public slots:
    void setCurrentColor(const QColor &color);
    void setCurrentSize(QSize size);
    void setShapeSelected(MyShape* shape);
    void moveSelectedShapes(MyShape*, QPoint);
    void setActiveFactory(ShapeFactory* f);
};

#endif // DRAWINGAREA_H
