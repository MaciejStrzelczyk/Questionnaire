#include "createaccount.h"
#include "ui_createaccount.h"

createAccount::createAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createAccount)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked, this, &createAccount::clickPushButton);

    connect(ui->pushButton, &QPushButton::clicked, this, &createAccount::onButtonOkClicked);


    qDebug() << "create";
    qDebug() << QSqlDatabase::drivers();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setUserName("test");
    db.setDatabaseName("C:/SQL/test");
    db.open();
    if(db.isOpen())
    {
        qDebug() << "Connect to database";
    }
    else
    {
        qDebug() << "don't connected";
    }

}

createAccount::~createAccount()
{
    delete ui;
}
void createAccount::clickPushButton()
{
    this->close();
}

void createAccount::onButtonOkClicked()
{
    QString dane = ui->lineEdit->text();
    emit createAccount::danePrzeslane(dane, this->db);
    close();
}
