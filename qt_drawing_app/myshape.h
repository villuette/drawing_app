#ifndef MYSHAPE_H
#define MYSHAPE_H

#include <QWidget>

class MyShape : public QWidget
{
    Q_OBJECT
public:
    MyShape(QWidget *parent = nullptr);
    QString name;
signals:

};

#endif // MYSHAPE_H
