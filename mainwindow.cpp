#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Model/tcities.h"
#include <QFile>
#include <string>
#include <QtCharts/QtCharts>
#include <map>


//using namespace QtCharts;

TCities* cities=nullptr;
QChart* chart;
QBarSeries* series;
//QValueAxis *axisX;
QBarCategoryAxis *axisX;
QValueAxis *axisY;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    cities=new TCities();
//    ui->pteLog->appendPlainText("Database is created");
    on_actionNew_triggered();
    //int a;
    //a=2001;
    for (int i=2000; i<2015; i++) ui->cbCityNames->addItem((QString::number(i)));

    chart=new QChart();
    series=new QBarSeries();

    QChartView *chartView = new QChartView(chart);
    chartView->resize(200,200);
    chartView->setRenderHint(QPainter::Antialiasing);
    auto layout=new QVBoxLayout();
    layout->addWidget(chartView,300);
    ui->tabWidget->widget(4)->setLayout(layout);

    axisX=new QBarCategoryAxis();
    axisY=new QValueAxis();

    //setCentralWidget(chartView);

    //QWidget* w=new QWidget();
    //w->setLayout(layout);
    //layout->addStretch(300);

   // connect(ui->comboBox_2,SIGNAL(currentIndexChanged(const QString&)),
     //       this,SLOT(on_comboBox_2_currentIndexChanged(const QString&)));
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
            this->on_pushButton_4_clicked();//Список городов

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


void MainWindow::on_pushButton_3_clicked()
{

    int year=ui->cbCityNames->currentText().toInt();
    TCities* selectedCities=cities->CitiesByYear(year);
    ui->lwSelectedCities->clear();
    if (selectedCities==nullptr) return;
    for(int i=0;i<selectedCities->Count();i++)
        ui->lwSelectedCities->addItem(QString::fromStdString(selectedCities->GetList()[i]->GetName()+" "+
                                                             std::to_string(selectedCities->GetList()[i]->GetYear())+" "+
                                                             std::to_string(selectedCities->GetList()[i]->GetCityPopulation())));
    delete selectedCities;
}


void MainWindow::on_actionExit_triggered()
{
  this->close();
}


void MainWindow::on_pushButton_5_clicked()
{   std::string name=ui->comboBox_2->currentText().toStdString();

   int count=cities->CitiesCensuses(name);
  ui->lCount->setText(QString::number(count));
  auto names=cities->GetBegin();
  auto namesEnd=cities->GetEnd();
  series->clear();
  QBarSet* set=new QBarSet("");
  QStringList categories;

  chart->setTitle(QString::fromStdString(name));
  int max=0;
  for(;names!=namesEnd;++names)
     if ((*names)->GetName()==name)
     {
         ui->pteLog->appendPlainText(QString::fromStdString((*names)->GetName()));
         *set<<(*names)->GetCityPopulation();
         categories.append(QString::number((*names)->GetYear()));
         if ((*names)->GetCityPopulation()>max)
             max=(*names)->GetCityPopulation();
     };
  axisY->setRange(0,max);
    axisX->clear();
    axisX->append(categories);
    series->append(set);
    series->attachAxis(axisX);
    chart->addSeries(series);
    chart->addAxis(axisX,Qt::AlignBottom);
    chart->addAxis(axisY,Qt::AlignLeft);


}


void MainWindow::on_pushButton_4_clicked()
{
    ui->listWidget_3->clear();
       std::map<std::string, TCity*> elem=cities->CitiesMillionaire();
       std::map<std::string,TCity*>::iterator it = elem.begin();
       for(;it != elem.end(); ++it)
       {
          ui->listWidget_3->addItem(QString::fromStdString(it->first));
       }

}


void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    ui->pteLog->appendPlainText(QString::number(index));
      if (index==3)
      {
          ui->comboBox_2->clear();
          std::vector<std::string> cityNames=cities->GetCityNames();
          auto it=cityNames.begin();
          for(;it!=cityNames.end();++it)
          {
              ui->comboBox_2->addItem(QString::fromStdString((*it)));
          }

      }

}


void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    //ui->pteLog->appendPlainText(arg1);
}


void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    //ui->pteLog->appendPlainText(QString::number(index));
}


void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    //ui->pteLog->appendPlainText(QString::fromStdString(cities->GetList()[arg1]));

}


void MainWindow::on_comboBox_2_activated(int index)
{
    if (index==-1) return;
    ui->pteLog->appendPlainText(QString::fromStdString(cities->GetList()[index]->GetName()));

}

