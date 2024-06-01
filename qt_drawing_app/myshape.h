#ifndef MYSHAPE_H
#define MYSHAPE_H

#include <QWidget>
#include <QPainter>
#include <QPen>
class MyShape : public QWidget
{
    Q_OBJECT
protected:
    QPainter* painter;
    QPen pen;
    virtual void draw(QPainter*) = 0;
public:
    MyShape(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void setPen(QPen pen);
    QPen getPen();
    void setSize(QSize size);
signals:
    void shapeSelected(MyShape* shape);
};

#endif // MYSHAPE_H
