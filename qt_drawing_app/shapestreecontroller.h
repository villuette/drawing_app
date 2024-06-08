#ifndef SHAPESTREECONTROLLER_H
#define SHAPESTREECONTROLLER_H


#include <QTreeView>
#include <QObject>
#include <iobserver.h>
#include <QStandardItemModel>
#include <mytreeitem.h>
#include <myshapegroup.h>
#include <iobservable.h>
class ShapesTreeController : public QObject, public virtual IObserver, public virtual IObservable
{
    Q_OBJECT
    ShapesStorage* allShapes; //optional: replace straight links with copied objects
    ShapesStorage* selectedShapes;
    ShapesStorage* selectedShapeInStore; //contains only 1 shape that clicked on tree (for type-conversion)
    QTreeView* tree;
    QStandardItemModel* model;
    int uid = 0;
    MyTreeItem* processNode(MyShape* shape);
    std::vector<IObserver*> observers;
public:
    ShapesTreeController();
    void bindTreeView(QTreeView*);
    void onItemClicked(const QModelIndex &index);
    void updateState(ShapesStorage* allShapes, ShapesStorage* selectedShapes) override;

    //IObservable:
    void addObserver(IObserver*) override;
    void notifyObservers() override;
};

#endif // SHAPESTREECONTROLLER_H
