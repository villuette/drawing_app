#ifndef MYTREEITEM_H
#define MYTREEITEM_H

#include <QStandardItem>
#include <myshape.h>

class MyTreeItem : public QStandardItem
{
    MyShape* shape;
public:
    MyShape* getShape();
    MyTreeItem(QString text, MyShape* shape);
};

#endif // MYTREEITEM_H
