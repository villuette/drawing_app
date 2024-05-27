#ifndef SHAPESELECTOR_H
#define SHAPESELECTOR_H

#include <QComboBox>
#include <QWidget>
#include <myshape.h>
#include <QMap>
#include <mycircle.h>
#include <myrectangle.h>
#include <QDebug>
class ShapeSelector : public QComboBox
{
    Q_OBJECT
    MyShape* shape;
    QMap<QString, MyShape*> shape_string_map;
    QMap<QString, MyShape*>::iterator it;

public:
    ShapeSelector(QWidget* parent = nullptr);
    MyShape* GetShape();
    void SetShape(MyShape* shape);
    void SetShape(QString name);
};

#endif // SHAPESELECTOR_H
