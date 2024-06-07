#include "shapesfilemanager.h"

ShapesFileManager::ShapesFileManager(QWidget* parent)
    :QMenuBar(parent)
{

}
void ShapesFileManager::writeStorageToFile(QTextStream &write_stream, ShapesStorage *store){ //spontaneously crashed (review later)
    for(MyShape* sh : *store){
        write_stream << sh->getShapeDataStringified();
    }
}
//shapes-newbies need to be created with DrawingArea as parent widget (QWidget will be enough)
//before shapes are created, we should pick the correct factory to initialize (need access to ShapeSelector/static method)
//on the other hand, DrawingArea is the only responsible for objects creating. (need access to DrawingArea)
//if i send DrawingArea, i should make shape creator method public
//or, due to task, just get the factory without other things from selector (add public method)
//now, this becomes another responsible object for shapes creating (review later)
ShapesStorage* ShapesFileManager::buildFromFile(QTextStream &read_stream, ShapeSelector *sel, DrawingArea *dr){
    ShapesStorage* store = new ShapesStorage();

    while(!read_stream.atEnd()){ //TODO workaround with groups
        QString shapeType = read_stream.readLine();
        MyShape* shapeEntity; //shape or group
        if (shapeType == "MyShapeGroup"){ //TODO reverse if-else
            int amount = read_stream.readLine().toInt();
            auto groupstore = new ShapesStorage();
            for (int i = 0; i < amount; i++){
                auto innerShapeType = read_stream.readLine();
                groupstore->addShape(readShape(read_stream, sel, dr, innerShapeType));
            }
            for (MyShape* sh : *groupstore){
                disconnect(sh, &MyShape::shapeMoved, dr, &DrawingArea::moveSelectedShapes);
                disconnect(sh, &MyShape::shapeSelected, dr, &DrawingArea::setShapeSelected);
            }
            shapeEntity = new MyShapeGroup(groupstore, dr);
            connect(shapeEntity, &MyShapeGroup::shapeSelected, dr, &DrawingArea::setShapeSelected);
            connect(shapeEntity, &MyShapeGroup::shapeMoved, dr, &DrawingArea::moveSelectedShapes);

        } else {
            shapeEntity = readShape(read_stream, sel, dr, shapeType);
        }
        store->addShape(shapeEntity);
    }
    return store; //function only creates new store and nothing more
}
MyShape* ShapesFileManager::readShape(QTextStream &read_stream, ShapeSelector *sel, DrawingArea *dr, QString shapeType){
    QRegularExpression re(".*: (\\d+), .*: (\\d+)");
    qDebug() << "shapeType: " << shapeType;

    sel->selectFromName(shapeType);

    QString location = read_stream.readLine();
    int xpos = re.match(location).captured(1).toInt();
    int ypos = re.match(location).captured(2).toInt();
    qDebug() <<"location: "<< xpos << ypos;

    //DrawingArea shapes' creator also configures necessary signals for shapes to work with
    auto shape = dr->createShape(QPoint(xpos, ypos));

    QString shapeSize = read_stream.readLine();
    int sh_w = re.match(shapeSize).captured(1).toInt();
    int sh_h = re.match(shapeSize).captured(2).toInt();
    qDebug() << "sizes: " << sh_w << sh_h;

    QColor color = QColor(read_stream.readLine());
    qDebug() << "color: " << color.name();

    shape->configureOnLoad(QPoint(xpos,ypos), QSize(sh_w, sh_h), QPen(color, shape->getPen().width()));
    shape->show();
    return shape;
}
