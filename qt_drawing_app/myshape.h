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
    virtual void draw(QPainter*) = 0;
    QPoint startMovePosition;
    bool isMoved = false;
public:
    MyShape(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void setPen(QPen pen);
    QPen getPen();
    void setSize(QSize size);
    void setStartMovePosition(QPoint p);
    QPoint getStartMovePosition();
    void moveBy(QPoint vect);
signals:
    void shapeSelected(MyShape* shape);
    void shapeMoved(MyShape* shape, QPoint vect);
    //TODO conditional connecting (change size, pen)
};

#endif // MYSHAPE_H
