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

     connect(ui->pushButton ,&QPushButton::clicked, this, &MainWindow::clickPushButton);



}

MainWindow::~MainWindow()
{
    delete ui;
     this->close();
}

void MainWindow::clickPushButton()
{

    ui->label->setText(db.databaseName());


}

void MainWindow::clickRadioButton()
{

}
void MainWindow::odebranoDane(const QSqlQuery &dane, const QSqlDatabase &db) {
    qDebug() << "------------";

    ui->label->setText(dane.value(1).toString() + " " + dane.value(2).toString());
    this->db = db;
    this->userName = dane.value(5).toString();


//    QSqlQuery query;
//    if (query.exec("select * from user where username = '" + this->userName + "'"  ))
//    {
//        while (query.next())
//        {
//            QString wartosc = query.value(3).toString();  // Zakładając, że chcesz pobrać pierwszą kolumnę
//            ui->label_2->setText(wartosc);
//            qDebug() << wartosc;
//        }
//    }
//    else
//    {
//        qDebug() << "Błąd zapytania SQL: " << query.lastError().text();
//    }


}


void MainWindow::on_actionExit_triggered()
{
    this->close();
}


void MainWindow::on_actionAdd_triggered()
{
    qDebug() << "Add action";
}

