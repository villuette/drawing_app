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
    model->setHorizontalHeaderLabels(QStringList(QString("[ object browser ]")));
    //opt: disconnect from previous tree sel model (for consistence)
    connect(tree->selectionModel(), &QItemSelectionModel::currentChanged, this, &ShapesTreeController::onItemClicked);
}
void ShapesTreeController::updateState(ShapesStorage *_allShapes, ShapesStorage *_selectedShapes){
    allShapes = _allShapes;
    selectedShapes = _selectedShapes;
    tree->selectionModel()->clear();
    model->clear();
    uid = 0;
    model->setHorizontalHeaderLabels(QStringList(QString("[ object browser ]")));
    QStandardItem* root = new QStandardItem("<root>");
    for (MyShape* shape : *_allShapes){
        auto generated_node = processNode(shape);
        if (selectedShapes->contains(shape)) {
            generated_node->setBackground(Qt::green);
        }
        root->appendRow(generated_node);
    }
    model->appendRow(root);
    tree->expandAll();
}
void ShapesTreeController::onItemClicked(const QModelIndex &index){ //groups selecting fixed
    QStandardItem *item = model->itemFromIndex(index);
    MyTreeItem* item_casted = dynamic_cast<MyTreeItem*>(item);
    if(item_casted){
        auto parentFinder = item_casted;
        MyTreeItem* maxParentAccepted = nullptr;
        while(parentFinder = dynamic_cast<MyTreeItem*>(parentFinder->parent())){
             maxParentAccepted = parentFinder;
        }
        if(maxParentAccepted){
            if (auto mygroup = qobject_cast<MyShapeGroup*>(maxParentAccepted->getShape())){
                selectedShapeInStore->addShape(mygroup);
                notifyObservers();
                selectedShapeInStore->purge();
                return;
            }
        }
        selectedShapeInStore->addShape(item_casted->getShape()); //check for deletion
        notifyObservers();
        selectedShapeInStore->purge();
    }
}
MyTreeItem* ShapesTreeController::processNode(MyShape *shape){
    auto node = new MyTreeItem(shape->getType() + "#" + QString::number(uid++), shape);
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
