#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Model/tcities.h"
#include <QFile>


TCities* cities=nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    cities=new TCities();
//    ui->pteLog->appendPlainText("Database is created");
    on_actionNew_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete cities;
}




void MainWindow::on_pushButton_clicked()
{
    //QDate date=new QDate();
    if (cities==nullptr) {
        ui->pteLog->appendPlainText("Database is not created");
        return;
    }
    cities->Add(new TCity(ui->teCityName->toPlainText().toStdString(),
                          ui->tePopulation->toPlainText().toInt(),
                          ui->teYear->toPlainText().toInt()));
    //QString qs=QString::fromStdString("asd");
    ui->listwCities->addItem(ui->teCityName->toPlainText());
    ui->pteLog->appendPlainText("Add "+ui->teCityName->toPlainText());
}


void MainWindow::on_actionNew_triggered()
{
    cities=new TCities();
    ui->pteLog->appendPlainText("Database is created");

}


void MainWindow::on_listwCities_itemClicked(QListWidgetItem *item)
{
    int index=ui->listwCities->currentIndex().row();
    ui->pteLog->appendPlainText(QString::number(index));
    ui->teCityName->setText(QString::fromStdString(cities->GetList()[index]->GetName()));
    ui->tePopulation->setText(QString::number(cities->GetList()[index]->GetCityPopulation()));
    ui->teYear->setText(QString::number(cities->GetList()[index]->GetYear()));

}


void MainWindow::on_actionSave_data_triggered()
{
    cities->Save("database.txt");
}


void MainWindow::on_actionLoad_data_triggered()
{
    if (QFile::exists("database.txt"))
    {

        cities->Load("database.txt");
        int count=cities->Count();
        for(int i=0;i<count;i++)
        {

            TCity* city=cities->GetList()[i];
            /*
            ui->teCityName->setText(QString::fromStdString(city->GetName()));
            ui->tePopulation->setText(QString::number(city->GetCityPopulation()));
            ui->teYear->setText(QString::number(city->GetYear()));
            */
            ui->listwCities->addItem(QString::fromStdString(city->GetName()));
        }

    }
    else
        ui->pteLog->appendPlainText("File is not exists");
}


void MainWindow::on_pushButton_2_clicked()
{
    if (ui->listwCities->currentItem()==nullptr) return;
    //ui->pteLog->appendPlainText((ui->listwCities->currentItem()->text()));
    int index=ui->listwCities->currentIndex().row();
    //ui->listwCities->removeItemWidget(ui->listwCities->currentItem());
     ui->listwCities->takeItem(ui->listwCities->row(ui->listwCities->currentItem()));
    //ui->listwCities->update();
    cities->RemoveAt(index);
}

