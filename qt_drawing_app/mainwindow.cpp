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
        selector->selectFromName(text);
    }
}



void MainWindow::on_width_slider_valueChanged(int value)
{
    QSlider* width_slider = qobject_cast<QSlider*>(sender());
    if(width_slider){
        ui->sizePicker->changeWidth(value);
    }
}


void MainWindow::on_height_slider_valueChanged(int value)
{
    QSlider* width_slider = qobject_cast<QSlider*>(sender());
    if(width_slider){
        ui->sizePicker->changeHeight(value);
    }
}


void MainWindow::on_sizePicker_sizeChanged(const QSize & size)
{
    SizePicker* sp = qobject_cast<SizePicker*>(sender());
    if(sp){
        ui->frame->setCurrentSize(size);
    }
}


void MainWindow::on_pushButton_colorChanged(const QColor & color)
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (btn){
        ui->frame->setCurrentColor(color);
    }
}

