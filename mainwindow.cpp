#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_createaccount.h"
#include "createaccount.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked, this, &MainWindow::clickPushButton);
    connect(ui->pushButton_2,&QRadioButton::clicked, this, &MainWindow::clickRadioButton);


    qDebug() << "a";
    qDebug() << QSqlDatabase::drivers();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(QCoreApplication::applicationDirPath()+"/test.db");
    if(db.open())
    {
        qDebug() << "Connect to database";
    }
    else
    {
        qDebug() << "don't connected";
    }
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
    createAccount accountScrean;
    accountScrean.setModal(true);
    accountScrean.exec();


}


