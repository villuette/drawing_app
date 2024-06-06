#ifndef SELECTIONAREA_H
#define SELECTIONAREA_H

#include <QWidget>
#include <QPainter>
#include <shapesstorage.h>
#include <QMouseEvent>
#include <QPoint>
#include <myshapegroup.h>

class SelectionArea : public QWidget //movement and resize behaviour
{
    Q_OBJECT
    ShapesStorage *storeof_selected;
    QPoint press_location;
public:
    explicit SelectionArea(ShapesStorage *selected, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*) override;
    QRect calculateSelectionArea();
signals:
    void areaMoved(QPoint vector);
    void areaResized(QSize size_diff);
};

#endif // SELECTIONAREA_H
