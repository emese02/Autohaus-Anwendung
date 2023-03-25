#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTableWidget>
#include <QTableWidgetItem>

#include <QStandardItemModel>
#include <QLabel>
#include <QFile>
#include <QDebug>
#include <QTextStream>

#include <QMessageBox>
#include <QTableView>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include "auto.h"
#include "second_window.h"
using namespace electric_auto;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    CSV_File_Repository *auto_repo = new CSV_File_Repository();
    auto_repo->initialize_repository();
    this->auto_controller = new Controller_CSV(*auto_repo);

    ui->setupUi(this);
    ui->pushButton_3->setText("Choose change/add!");
    ui->pushButton_3->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// show data
void MainWindow::on_pushButton_2_clicked()
{
      second_Window = new Second_Window(this->auto_controller,this);
      second_Window->show();
}

// add car
void MainWindow::on_pushButton_3_clicked()
{
    QString brand = ui->lineEdit_8->text();
    QString model = ui->lineEdit_7->text();
    QString year = ui->lineEdit_6->text();
    QString km = ui->lineEdit_5->text();
    QString price = ui->lineEdit_4->text();
    QString hp = ui->lineEdit_3->text();
    QString fuel = ui->lineEdit_2->text();

    Auto new_car(model.toStdString(), brand.toStdString(),year.toInt(),
                 km.toFloat(),price.toFloat(),hp.toInt(),fuel.toStdString());

    if (change_add)
    {
        QString ID = ui->lineEdit_12->text();
        this->auto_controller->modify_car(ID.toStdString(),new_car);
    }
    else
        this->auto_controller->add_car(new_car);
}

// add chosen
void MainWindow::on_radioButton_clicked()
{
    change_add = false;
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_3->setText("Car will be added!");
}

// modify chosen
void MainWindow::on_radioButton_2_clicked()
{
    change_add = true;
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_3->setText("Car attributes will be modified!");
}

// add to favorites
void MainWindow::on_pushButton_4_clicked()
{
    QString id = ui->lineEdit_14->text();
    this->auto_controller->add_favorite(id.toStdString());
}

// delete car
void MainWindow::on_pushButton_clicked()
{
    QString id = ui->lineEdit_11->text();
    this->auto_controller->delete_car(id.toStdString());
}

// set file name
void MainWindow::on_pushButton_6_clicked()
{
    QString name = ui->lineEdit_9->text();
    this->auto_controller->set_filename(name.toStdString());
}

// update data
void MainWindow::on_pushButton_5_clicked()
{
     this->auto_controller->update();
}

// load cars
void MainWindow::on_pushButton_7_clicked()
{
    this->auto_controller->initialize();
}

