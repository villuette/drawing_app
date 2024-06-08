#include "mytreeitem.h"

MyTreeItem::MyTreeItem(QString text, MyShape* shape)
    :QStandardItem(text)
{
    this->shape = shape;
}
MyShape* MyTreeItem::getShape(){
    return this->shape;
}
