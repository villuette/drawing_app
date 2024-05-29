#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QFrame>
#include <QWidget>
#include <shapesstorage.h>
#include <QMouseEvent>
#include <mycircle.h>
#include <QLayout>
class DrawingArea : public QFrame
{
    Q_OBJECT
    ShapesStorage* store; //creates and responsible for keeping objects
    //TODO fabric
public:
    DrawingArea(QWidget* parent = nullptr);
    void BindStorage(ShapesStorage* _store); //accessed for loading and saving files
    void paintEvent(QPaintEvent* e) override; //TODO redraw all contained shapes
    void mousePressEvent(QMouseEvent* e) override;
    void mouseReleaseEvent(QMouseEvent* e) override;
    MyShape* createShape(QPoint coords);
};

#endif // DRAWINGAREA_H
