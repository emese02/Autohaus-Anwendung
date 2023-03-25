#ifndef SECOND_WINDOW_H
#define SECOND_WINDOW_H

#include <QDialog>
#include "auto_controller.h"

using namespace controller;
namespace Ui {
class Second_Window;
}

class Second_Window : public QDialog
{
    Q_OBJECT

public:

    explicit Second_Window(Controller_CSV *controller, QWidget *parent = nullptr);
    ~Second_Window();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Second_Window *ui;
    Controller_CSV *auto_controller;
     void TableWidgetDisplay(std::vector<Auto> cars);
};

#endif // SECOND_WINDOW_H
