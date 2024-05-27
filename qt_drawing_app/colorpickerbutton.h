#ifndef COLORPICKERBUTTON_H
#define COLORPICKERBUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QColorDialog>
class ColorPickerButton : public QPushButton
{
    Q_OBJECT
    QColor paletteColor;
public:
    ColorPickerButton(QWidget* parent = nullptr);
    void mousePressEvent(QMouseEvent* e) override;
    QColor GetColor();
    void SetColor(QColor color);
};

#endif // COLORPICKERBUTTON_H
