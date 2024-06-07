#ifndef MYSHAPE_H
#define MYSHAPE_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QPoint>
#include <QPainter>
class MyShape : public QWidget
{
    Q_OBJECT
protected:
    QPainter* painter;
    QPen pen;
    QPoint startMovePosition;
    bool wasMoved = false;
public:
    virtual void draw(QPainter*) = 0;
    MyShape(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *) final;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    virtual void setPen(QPen pen);
    virtual QPen getPen();
    virtual void setSize(QSize size);
    void setStartMovePosition(QPoint p);
    QPoint getStartMovePosition();
    virtual void moveBy(QPoint vect);
    virtual void drawSelection(QPainter* p);
    virtual QString getShapeDataStringified();
    virtual QString getType() = 0;
signals:
    void shapeSelected(MyShape* shape);
    void shapeMoved(MyShape* shape, QPoint vect);
    //TODO conditional connecting (change size, pen)
};

#endif // MYSHAPE_H
