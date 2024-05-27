#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

//shape selector change
void MainWindow::on_comboBox_currentTextChanged(const QString &text)
{
    ShapeSelector* selector = qobject_cast<ShapeSelector*>(sender());
    if (selector) {
        selector->SetShape(text);
        auto shape = selector->GetShape();
        const std::type_info& info = typeid(*shape);
        qDebug() << "selected shape changed: " + QString(info.name());
    }
}

