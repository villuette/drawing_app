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
class DrawingArea : public QFrame
{
    Q_OBJECT
    ShapesStorage* store; //destroys all contained shapes on program exit
    ShapesStorage* selectedStore; //contains only selected shapes
    QColor currentColor;
    QSize currentSize;
    QColor selectionColor;
    SelectionArea selectionArea;
    //TODO fabric
public:
    DrawingArea(QWidget* parent = nullptr);
    void BindStorage(ShapesStorage* _store); //accessed for loading and saving files
    void paintEvent(QPaintEvent* e) override; //TODO redraw all contained shapes
    void mousePressEvent(QMouseEvent* e) override;
    void mouseReleaseEvent(QMouseEvent* e) override;
    QColor getSelectionColor();
    MyShape* createShape(QPoint coords);
    QRect calculateSelectionArea();
    void drawSelectionArea();
    void keyReleaseEvent(QKeyEvent *event) override;
public slots:
    void setCurrentColor(const QColor &color);
    void setCurrentSize(QSize size);
    void setShapeSelected(MyShape* shape, QMouseEvent* e);
    void moveSelectedShapes(MyShape*, QPoint, QMouseEvent*);
    bool checkAreaLeaving();
    //TODO avoid leaving area
};

#endif // DRAWINGAREA_H
