#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

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
    void on_pushButton_clicked();

    void on_actionNew_triggered();

    void on_listwCities_itemClicked(QListWidgetItem *item);

    void on_actionSave_data_triggered();

    void on_actionLoad_data_triggered();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_actionExit_triggered();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_2_activated(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
