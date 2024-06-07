#ifndef SHAPESFILEMANAGER_H
#define SHAPESFILEMANAGER_H

#include <QWidget>
#include <QMenuBar>
#include <QMainWindow>
#include <shapesstorage.h>
class ShapesFileManager : QMenuBar
{
public:
    ShapesFileManager(QWidget* parent = nullptr);
    void writeStorageToFile(QTextStream &write_stream, ShapesStorage* store); //TODO make store immutable
    ShapesStorage* buildStorageFromFile(QTextStream &read_stream);
};

#endif // SHAPESFILEMANAGER_H
