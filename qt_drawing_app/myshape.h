#ifndef MYSHAPE_H
#define MYSHAPE_H

#include <QWidget>
#include <QPainter>
class MyShape : public QWidget
{
    Q_OBJECT
protected:
    QPainter* painter;
public:
    MyShape(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *) override;
    virtual void draw() = 0;
signals:

};

#endif // MYSHAPE_H
