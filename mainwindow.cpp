#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "ui_createaccount.h"
//#include "createaccount.h"
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widget_2->adjustSize();
    ui->widget_2->hide();
    ui->stackedWidget->setCurrentIndex(0);

    if(QString::compare(this->sex, "M", Qt::CaseInsensitive) )
    {
        ui->label_7->setText("Male");
        ui->toolButton->show();
        ui->toolButton_2->hide();
    }
    else
    {
        ui->label_7->setText("Female");
        ui->toolButton->hide();
        ui->toolButton_2->show();
    }


     connect(ui->pushButton_2 ,&QPushButton::clicked, this, &MainWindow::clickPushButton2);
     connect(ui->pushButton_4 ,&QPushButton::clicked, this, &MainWindow::clickPushButton4);
     connect(ui->pushButton_5 ,&QPushButton::clicked, this, &MainWindow::clickPushButton5);
     connect(ui->pushButton_6 ,&QPushButton::clicked, this, &MainWindow::clickPushButton6);



}

MainWindow::~MainWindow()
{
    delete ui;
     this->close();
}

void MainWindow::clickPushButton5()
{

     if(!(ui->widget_2->isHidden()))
     {
         ui->widget_2->hide();
     }
     else
     {
         ui->widget_2->show();
     }
}


void MainWindow::clickPushButton2()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::clickPushButton4()
{
     ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::clickPushButton6()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::clickRadioButton()
{

}


void MainWindow::odebranoDane(const QSqlQuery &dane, const QSqlDatabase &db) {
    qDebug() << "------------";
     qDebug() << dane.value(1).toString() + " " + dane.value(2).toString() + " " + " " + dane.value(6).toString();
    this->data = dane;
    ui->label_4->setText(dane.value(1).toString() + " " + dane.value(2).toString());
    this->db = db;
    this->userName = dane.value(5).toString();
    this->sex = dane.value(6).toString();
    qDebug() << this->sex;

}


void MainWindow::on_actionExit_triggered()
{
    this->close();
}


void MainWindow::on_actionAdd_triggered()
{
    qDebug() << "Add action";
}

