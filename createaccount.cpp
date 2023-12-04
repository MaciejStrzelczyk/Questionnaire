#include "createaccount.h"
#include "ui_createaccount.h"

createAccount::createAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createAccount)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked, this, &createAccount::clickPushButton);
}

createAccount::~createAccount()
{
    delete ui;
}
void clickPushButton()
{
    createAccount();
}
