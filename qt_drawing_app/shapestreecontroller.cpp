#include "shapestreecontroller.h"
#include "iobserver.h"
ShapesTreeController::ShapesTreeController()
    : model(new QStandardItemModel()),
    selectedShapeInStore(new ShapesStorage())
{

}
void ShapesTreeController::bindTreeView(QTreeView* attached_tree){
    tree = attached_tree;
    tree->setModel(model);
    //opt: disconnect from previous tree sel model (for consistence)
    connect(tree->selectionModel(), &QItemSelectionModel::currentChanged, this, &ShapesTreeController::onItemClicked);
}
void ShapesTreeController::updateState(ShapesStorage *_allShapes, ShapesStorage *_selectedShapes){
    qDebug() << "notification received";
    allShapes = _allShapes;
    selectedShapes = _selectedShapes;
    tree->selectionModel()->clear();
    model->clear();
    uid = 0;
    //tree->setSelectionModel(new QItemSelectionModel());
    //NAMES HAS TO BE UNIQUE
    MyTreeItem* core = new MyTreeItem("sometextRightHere", nullptr);
    for (MyShape* shape : *_allShapes){
        core->appendRow(processNode(shape));
        uid++;
    }

//    core->setBackground(Qt::red);ShapesTreeController
//    QStandardItem* foldedItem = new QStandardItem("folded text");
//    testitem->appendRow(foldedItem);
    model->appendRow(core);
    tree->expandAll();
}
void ShapesTreeController::onItemClicked(const QModelIndex &index){
    QStandardItem *item = model->itemFromIndex(index);
    MyTreeItem* item_casted = dynamic_cast<MyTreeItem*>(item);
    if(item_casted){
        qDebug() <<" shape:" << item_casted->getShape();
        selectedShapeInStore->addShape(item_casted->getShape()); //check for deletion
    }
//    item->setBackground(Qt::red);
}
MyTreeItem* ShapesTreeController::processNode(MyShape *shape){
    auto node = new MyTreeItem(shape->getType(), shape);
    if (auto group = qobject_cast<MyShapeGroup*>(shape)){ //check ifGroup at MyShape level
        for (auto inner_shape :  *group->getShapes()){
           node->appendRow(processNode(inner_shape));
        }
    }
    return node;
}

void ShapesTreeController::addObserver(IObserver* obs) {
    observers.push_back(obs);
}
void ShapesTreeController::notifyObservers(){
    for(auto obs: observers){
        obs->updateState(allShapes, selectedShapeInStore);
    }
}
