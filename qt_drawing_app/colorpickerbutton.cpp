#include "colorpickerbutton.h"

ColorPickerButton::ColorPickerButton(QWidget* parent)
    : QPushButton(parent)
{
    paletteColor = Qt::black;
}
void ColorPickerButton::mousePressEvent(QMouseEvent* e) { //changing to signal causes bugs with window handling
    QPushButton::mousePressEvent(e);
    auto color = QColorDialog::getColor();
    SetColor(color);
    setStyleSheet(QString("background-color:" + color.name()));
    emit colorChanged(paletteColor);
}
void ColorPickerButton::SetColor(QColor color){
    paletteColor = color;
}
QColor ColorPickerButton::GetColor(){
    return paletteColor;
}

