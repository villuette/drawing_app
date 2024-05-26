#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QColorDialog>
#include "iostream"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toolButton_clicked()
{
    QColorDialog* qcd = new QColorDialog();
    QObject* btn = qobject_cast<QObject*>(sender());
    if (btn !=NULL) {
        //TODO redefine property using with classes
        btn->setProperty("items_coloer", qcd->getColor());
    }
    qDebug() << btn->property("items_coloer").toString();
}

