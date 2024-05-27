#include "shapeselector.h"

ShapeSelector::ShapeSelector(QWidget* parent)
    : QComboBox(parent)
{
    shape_string_map = {{"MyCircle", new MyCircle()}, {"MyRectangle", new MyRectangle()}};


    int itemIdx = 0; //fill values to combobox
    for(it = shape_string_map.begin(); it != shape_string_map.end(); it++){
        insertItem(itemIdx++, it.key());
    }
}
MyShape* ShapeSelector::GetShape(){
    return shape;
}
void ShapeSelector::SetShape(MyShape* shape){
    this->shape = shape;
}
void ShapeSelector::SetShape(QString name){
    SetShape(shape_string_map[name]);
}

