#ifndef MYTREEITEM_H
#define MYTREEITEM_H

#include <QStandardItem>
#include <myshape.h>

class MyTreeItem : public QStandardItem
{
public:
    MyTreeItem();
    MyTreeItem(QString text);
    MyShape* shape;
};

#endif // MYTREEITEM_H
