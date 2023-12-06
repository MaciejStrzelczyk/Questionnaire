#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "ui_createaccount.h"
//#include "createaccount.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    qDebug() << "main1";
    //qDebug() << db.userName();
//    connect(ui->pushButton,&QPushButton::clicked, this, &MainWindow::clickPushButton);
//    connect(ui->pushButton_2,&QRadioButton::clicked, this, &MainWindow::clickRadioButton);
   // connect(dialog, &createAccount::danePrzeslane, this, &MainWindow::odebranoDane);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickPushButton()
{
    qDebug() << "end2";
}

void MainWindow::clickRadioButton()
{

}
void MainWindow::odebranoDane(const QString &dane, const QSqlDatabase &db) {
    ui->lineEdit->setText(dane);
    this->db = db;
    ui->label->setText(db.userName());

    qDebug()<< db.hostName();


    QSqlQuery query;
    //query.prepare("SELECT email FROM [test].[Tabele].User");
    if (query.exec("SELECT email FROM User where user_id=" + dane))
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


