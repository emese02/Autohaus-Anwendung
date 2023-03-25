#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "second_window.h"
#include "auto_controller.h"
#include <QString>

using namespace controller;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // true means change, add means false
    bool change_add = false;

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    Second_Window *second_Window;
    Controller_CSV *auto_controller;
    void TableWidgetDisplay();

};
#endif // MAINWINDOW_H
