#include "shapestreecontroller.h"
#include "iobserver.h"
ShapesTreeController::ShapesTreeController()
    //: tree(attached_tree)
    :model(new QStandardItemModel())
{

}
void ShapesTreeController::bindTreeView(QTreeView* attached_tree){
    tree = attached_tree;
    tree->setModel(model);
}
void ShapesTreeController::updateState(ShapesStorage *_allShapes, ShapesStorage *_selectedShapes){
    qDebug() << "notification received";
    allShapes = _allShapes;
    selectedShapes = _selectedShapes;
    //tree->setSelectionModel(new QItemSelectionModel());
    //NAMES HAS TO BE UNIQUE
    MyTreeItem* core = new MyTreeItem("sometextRightHere");
    core->shape = allShapes->begin().current->shape;
    connect(tree->selectionModel(), &QItemSelectionModel::currentChanged, this, &ShapesTreeController::onItemClicked);
//    core->setBackground(Qt::red);
//    QStandardItem* foldedItem = new QStandardItem("folded text");
//    testitem->appendRow(foldedItem);
    model->appendRow(core);
    tree->expandAll();
}
void ShapesTreeController::onItemClicked(const QModelIndex &index){
    QStandardItem *item = model->itemFromIndex(index);
    MyTreeItem* item_casted = dynamic_cast<MyTreeItem*>(item);
    if(item_casted){
        qDebug() << "VERY SUCCESS";
        qDebug() <<" shape:" << item_casted->shape;
    }

//    item->setBackground(Qt::red);
}
