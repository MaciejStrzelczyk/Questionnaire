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
}

void MainWindow::clickPushButton()
{

    ui->label->setText(db.databaseName());


}

void MainWindow::clickRadioButton()
{

}
void MainWindow::odebranoDane(const QString &dane, const QSqlDatabase &db) {
    qDebug() << "------------";

    ui->lineEdit->setText(dane);
    this->db = db;
    this->userName = dane;


    QSqlQuery query;
    if (query.exec("select email from user where username = '" + this->idUser + "'"  ))
    {
        while (query.next())
        {
            QString wartosc = query.value(0).toString();  // Zakładając, że chcesz pobrać pierwszą kolumnę
            ui->label_2->setText(wartosc);
        }
    }
    else
    {
        qDebug() << "Błąd zapytania SQL: " << query.lastError().text();
    }


}


