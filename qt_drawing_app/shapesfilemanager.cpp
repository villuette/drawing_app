#include "shapesfilemanager.h"

ShapesFileManager::ShapesFileManager(QWidget* parent)
    :QMenuBar(parent)
{

}
void ShapesFileManager::writeStorageToFile(QTextStream &write_stream, ShapesStorage *store){
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
    QRegularExpression re(".*: (\\d+), .*: (\\d+)");
    while(!read_stream.atEnd()){ //TODO workaround with groups
        QString shapeType = read_stream.readLine();
        qDebug() << "shapeType: " << shapeType;
//        auto factory = sel->getFactoryOnly(shapeType);
//        auto shape = factory->createShape(dr);
        sel->selectFromName(shapeType);


        QString location = read_stream.readLine();
        int xpos = re.match(location).captured(1).toInt();
        int ypos = re.match(location).captured(2).toInt();
        qDebug() <<"location: "<< xpos << ypos;

        auto shape = dr->createShape(QPoint(xpos, ypos));

        QString shapeSize = read_stream.readLine();
        int sh_w = re.match(shapeSize).captured(1).toInt();
        int sh_h = re.match(shapeSize).captured(2).toInt();
        qDebug() << "sizes: " << sh_w << sh_h;

        QColor color = QColor(read_stream.readLine());
        qDebug() << "color: " << color.name();

        shape->configureOnLoad(QPoint(xpos,ypos), QSize(sh_w, sh_h), QPen(color, shape->getPen().width()));
        shape->show();
        store->addShape(shape);
    }
    return store; //function only creates new store and nothing more
}
