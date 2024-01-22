#include "createaccount.h"
#include "ui_createaccount.h"
#include <QMessageBox>
#include <QLineEdit>

createAccount::createAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createAccount)
{
    ui->setupUi(this);

    ui->label_4->setVisible(false);

    connect(ui->pushButton,&QPushButton::clicked, this, &createAccount::clickPushButton);

    connect(ui->pushButton, &QPushButton::clicked, this, &createAccount::onButtonOkClicked);

    connect(ui->pushButton, &QPushButton::clicked, this, &createAccount::clearLineEdit);


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
    this->close();
}
void createAccount::clickPushButton()
{
    this->close();
}

void createAccount::onButtonOkClicked()
{

    QString userName = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QSqlQuery query;
    if (query.exec("select * from user where username = '" + userName + "'"  ))
    {
        if (query.next())
        {
            if(password == query.value(4).toString()) // Zakładając, że chcesz pobrać pierwszą kolumnę
            {
                emit createAccount::danePrzeslane(query, this->db);
                this->isAautentication = true;
            }
            else
            {
                ui->label_4->setVisible(true);
            }

        }
        else
        {
            ui->label_4->setVisible(true);
        }
    }
    else
    {
        qDebug() << "Błąd zapytania SQL: " << query.lastError().text();

    }


}

bool createAccount::getIsAutentication()
{
    return this->isAautentication;
}

void createAccount::clearLineEdit()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}
