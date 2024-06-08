#ifndef SHAPESTREECONTROLLER_H
#define SHAPESTREECONTROLLER_H


#include <QTreeView>
#include <QObject>
#include <iobserver.h>
#include <QStandardItemModel>
#include <mytreeitem.h>
class ShapesTreeController : public QObject, public virtual IObserver
{
    Q_OBJECT
    ShapesStorage* allShapes; //optional: replace straight links with copied objects
    ShapesStorage* selectedShapes;
    QTreeView* tree;
    QStandardItemModel* model;
public:
    ShapesTreeController();
    void bindTreeView(QTreeView*);
    void onItemClicked(const QModelIndex &index);
    void updateState(ShapesStorage* allShapes, ShapesStorage* selectedShapes) override;
};

#endif // SHAPESTREECONTROLLER_H
