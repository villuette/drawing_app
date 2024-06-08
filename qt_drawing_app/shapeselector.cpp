#include "shapeselector.h"
#include <mystickyfactory.h>
ShapeSelector::ShapeSelector(QWidget* parent)
    : QComboBox(parent)
{
    shape_string_map = {{"MyCircle", new MyCircleFactory()},
                        {"MyRectangle", new MyRectangleFactory()},
                        {"MyStickyShape", new MyStickyFactory()}};

    int itemIdx = 0; //fill values to combobox
    for(it = shape_string_map.begin(); it != shape_string_map.end(); it++){
        insertItem(itemIdx++, it.key());
    }
}
void ShapeSelector::selectFromName(QString name){ //or just send with signal without storing
    currentFactory = shape_string_map[name];
    emit factoryChanged(currentFactory);
}
ShapeFactory* ShapeSelector::getFactoryOnly(QString name){
    return shape_string_map[name];
}

