#include "sizepicker.h"

SizePicker::SizePicker(QWidget *parent)
    : QWidget{parent},
      pickedSize(20,20)
{}
void SizePicker::changeWidth(int value){
    pickedSize = QSize(value, pickedSize.height());
    emit sizeChanged(pickedSize);
}
void SizePicker::changeHeight(int value){
    pickedSize = QSize(pickedSize.width(), value);
    emit sizeChanged(pickedSize);
}
