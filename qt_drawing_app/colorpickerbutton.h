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
    QColor GetColor(); //TODO usless get;set; remove later
    void SetColor(QColor color);
signals:
    void colorChanged(const QColor &color);
};

#endif // COLORPICKERBUTTON_H
