#ifndef SELECTIONAREA_H
#define SELECTIONAREA_H

#include <QWidget>
#include <QPainter>

class SelectionArea : public QWidget
{
    Q_OBJECT
public:
    explicit SelectionArea(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*) override;

signals:

};

#endif // SELECTIONAREA_H
