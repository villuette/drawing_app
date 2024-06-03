#ifndef MYSHAPE_H
#define MYSHAPE_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QPoint>
class MyShape : public QWidget
{
    Q_OBJECT
protected:
    QPainter* painter;
    QPen pen;

    QPoint startMovePosition;
    bool isMoved = false;
public:
    virtual void draw(QPainter*) = 0;
    MyShape(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    virtual void setPen(QPen pen);
    virtual QPen getPen();
    virtual void setSize(QSize size);
    void setStartMovePosition(QPoint p);
    QPoint getStartMovePosition();
    virtual void moveBy(QPoint vect);
signals:
    void shapeSelected(MyShape* shape, QMouseEvent* e);
    void shapeMoved(MyShape* shape, QPoint vect, QMouseEvent* e);
    //TODO conditional connecting (change size, pen)
};

#endif // MYSHAPE_H
