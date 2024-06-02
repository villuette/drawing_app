#ifndef SELECTIONAREA_H
#define SELECTIONAREA_H

#include <QWidget>
#include <QPainter>
#include <shapesstorage.h>
#include <QMouseEvent>
#include <QPoint>
//#include <
class SelectionArea : public QWidget //movement and resize behaviour
{
    Q_OBJECT
    ShapesStorage *storeof_selected;
    ShapesStorage  *storeof_all; //used only to reach unselected shapes behind selection area
    QPoint press_location;
public:
    explicit SelectionArea(ShapesStorage* selected, ShapesStorage* main_store, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
signals:
    void areaMoved(QPoint vector);
    void areaResized(QSize size_diff);
};

#endif // SELECTIONAREA_H
