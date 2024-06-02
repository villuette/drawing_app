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
public:
    MyShape(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    //void mouseDoubleClickEvent(QMouseEvent*) override;
    void setPen(QPen pen);
    QPen getPen();
    void setSize(QSize size);
    void setStartMovePosition(QPoint p);
    QPoint getStartMovePosition();
signals:
    void shapeSelected(MyShape* shape);
};

#endif // MYSHAPE_H
