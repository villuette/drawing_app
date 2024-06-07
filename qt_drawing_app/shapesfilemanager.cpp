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
ShapesStorage* ShapesFileManager::buildStorageFromFile(QTextStream &read_stream){

}