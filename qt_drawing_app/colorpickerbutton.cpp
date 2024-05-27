#include "colorpickerbutton.h"

ColorPickerButton::ColorPickerButton(QWidget* parent)
    : QPushButton(parent)
{}
void ColorPickerButton::mousePressEvent(QMouseEvent* e) { //TODO change event to signal
    QPushButton::mousePressEvent(e);
    auto color = QColorDialog::getColor();
    SetColor(color);
    setStyleSheet(QString("background-color:" + color.name()));
    qDebug() << "Color changed: " + GetColor().name();

}
void ColorPickerButton::SetColor(QColor color){
    paletteColor = color;
}
QColor ColorPickerButton::GetColor(){
    return paletteColor;
}
