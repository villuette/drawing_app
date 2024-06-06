#ifndef SHAPESELECTOR_H
#define SHAPESELECTOR_H

#include <QComboBox>
#include <QWidget>
#include <myshape.h>
#include <QMap>
#include <mycircle.h>
#include <myrectangle.h>
#include <QDebug>
#include <shapefactory.h>
#include <mycirclefactory.h>
#include <myrectanglefactory.h>
class ShapeSelector : public QComboBox
{
    Q_OBJECT
    ShapeFactory* currentFactory;
    QMap<QString, ShapeFactory*> shape_string_map;
    QMap<QString, ShapeFactory*>::iterator it;
public:
    ShapeSelector(QWidget* parent = nullptr);
    void selectFromName(QString name);
signals:
    void factoryChanged(ShapeFactory* f);

};

#endif // SHAPESELECTOR_H
