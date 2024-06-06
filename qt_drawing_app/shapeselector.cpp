#include "shapeselector.h"

ShapeSelector::ShapeSelector(QWidget* parent)
    : QComboBox(parent)
{
    shape_string_map = {{"Circle", new MyCircleFactory()}, {"Rectangle", new MyRectangleFactory()}};

    int itemIdx = 0; //fill values to combobox
    for(it = shape_string_map.begin(); it != shape_string_map.end(); it++){
        insertItem(itemIdx++, it.key());
    }
    //qDebug() << shape_string_map.first();
}
void ShapeSelector::selectFromName(QString name){ //or just send with signal without storing
    currentFactory = shape_string_map[name];
    emit factoryChanged(currentFactory);
}

