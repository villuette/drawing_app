#ifndef SIZEPICKER_H
#define SIZEPICKER_H

#include <QWidget>
#include <QSpinBox>
#include <QChildEvent>
#include <QSize>
class SizePicker : public QWidget
{
    Q_OBJECT
    QSize pickedSize;
    QSpinBox* spin_width;
    QSpinBox* spin_height;
public:
    SizePicker(QWidget *parent = nullptr);
signals:
    void sizeChanged(const QSize &size);
public slots:
    void setPickedWidth(const int &value);
    void setPickedHeight(const int &value);
};

#endif // SIZEPICKER_H
