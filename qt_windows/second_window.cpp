#include "second_window.h"
#include "ui_second_window.h"
#include "auto.h"
#include <iostream>
#include "auto_controller.h";
#include "auto_repository.h"
#include <QTableWidget>
#include <QStandardItemModel>
#include <QtCore>
#include <fstream>
#include <sstream>
using namespace electric_auto;

Second_Window::Second_Window(Controller_CSV *controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Second_Window)
{
    this->auto_controller = controller;
    ui->setupUi(this);
    this->resize(1260,900);
}

Second_Window::~Second_Window()
{
    delete ui;
}

void Second_Window::TableWidgetDisplay(std::vector<Auto> cars)
{
    QTableWidget *table = new QTableWidget(this);
    table->setRowCount(cars.size());
    table->setColumnCount(8);

    QStringList hLabels;
    hLabels << "ID" << "Brand" << "Model" << "Year" << "Km" << "Price" << "Horse Power" << "Fuel";
    table->setHorizontalHeaderLabels(hLabels);

    int nr_cars = cars.size();
    for (int i = 0; i < nr_cars; i++)
    {
        table->setRowHeight(i,75);
        QTableWidgetItem *item;
        for (int j = 0; j < table->columnCount(); j++)
        {
            item = new QTableWidgetItem;
            item->setTextAlignment( Qt::AlignCenter );
            switch (j)
            {
             case 0:
                   item->setText(QString::fromStdString(cars[i].get_id()));
                   break;
             case 1:
                    item->setText(QString::fromStdString(cars[i].get_brand()));
                    break;
             case 2:
                    item->setText(QString::fromStdString(cars[i].get_model()));
                    break;
             case 3:
                    item->setText(QString::number(cars[i].get_year()));
                    break;
             case 4:
                    item->setText( QString::number(cars[i].get_km()));
                    break;
             case 5:
                    item->setText(QString::number(cars[i].get_price()));
                    break;
             case 6:
                    item->setText(QString::number(cars[i].get_hp()));
                    break;
             case 7:
                    item->setText(QString::fromStdString(cars[i].get_fuel()));
                    break;
             default:
                break;
            };

            table->setItem(i,j,item);
        }
    }
    table->setStyleSheet("QTableWidget{"
                             "background-color: #eeeede;"
                             "alternate-background-color:#B19AC9;"
                             "selection-background-color:B5B76F;"
                             "}");

    table->setAlternatingRowColors(true);
    table->setShowGrid(true);
    table->setGridStyle(Qt::DotLine);
    table->setSortingEnabled(true);

    table->resize(5000,5000);
    table->show();
}

void Second_Window::on_pushButton_clicked()
{
    // show all
    Second_Window::TableWidgetDisplay(this->auto_controller->get_all());
}


void Second_Window::on_pushButton_7_clicked()
{
    // search by model
    QString model = ui->lineEdit_8->text();
    Second_Window::TableWidgetDisplay(this->auto_controller->find_cars_model(model.toStdString()));
}


void Second_Window::on_pushButton_6_clicked()
{
    // search by brand
    QString brand = ui->lineEdit_7->text();
    Second_Window::TableWidgetDisplay(this->auto_controller->find_cars_brand(brand.toStdString()));
}


void Second_Window::on_pushButton_5_clicked()
{
    // filter by age
    QString age = ui->lineEdit_2->text();
    Second_Window::TableWidgetDisplay(this->auto_controller->filter_cars_age(age.toInt()));
}


void Second_Window::on_pushButton_4_clicked()
{
    // filter by km
    QString km = ui->lineEdit->text();
    Second_Window::TableWidgetDisplay(this->auto_controller->filter_cars_km(km.toFloat()));
}


void Second_Window::on_pushButton_2_clicked()
{
    // exit
    accept();
}

// zeigen Lieblingsautos
void Second_Window::on_pushButton_3_clicked()
{
    Second_Window::TableWidgetDisplay(this->auto_controller->get_favorite());
}

