#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_width_slider_valueChanged(int value);

    void on_height_slider_valueChanged(int value);

    void on_sizePicker_sizeChanged(const QSize &);

    void on_pushButton_colorChanged(const QColor &);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
