
#ifndef SHAPESFILEMANAGER_H
#define SHAPESFILEMANAGER_H

#include <QWidget>
#include <QMenuBar>
#include <QMainWindow>
#include <shapesstorage.h>
#include <QRegularExpression>
#include <shapeselector.h>
#include <drawingarea.h>
class ShapesFileManager : QObject
{
    MyShape* readShape(QTextStream &read_stream, ShapeSelector *sel, DrawingArea *dr, QString type);
public:
    ShapesFileManager();
    void writeStorageToFile(QTextStream &write_stream, ShapesStorage* store); //TODO make store immutable
    ShapesStorage* buildFromFile(QTextStream &read_stream, ShapeSelector *sel, DrawingArea *dr); //TODO rename with consistency
};

#endif // SHAPESFILEMANAGER_H
