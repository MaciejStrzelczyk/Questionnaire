#include "addnewaccount.h"
#include "ui_addnewaccount.h"


addnewaccount::addnewaccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addnewaccount)
{
    ui->setupUi(this);
    ui->label_8->setVisible(false);

    connect(ui->pushButton,&QPushButton::clicked, this, &addnewaccount::onButtonCreateClicked);
    connect(ui->pushButton_2,&QPushButton::clicked, this, &addnewaccount::onButtonLogInClicked);


}

addnewaccount::~addnewaccount()
{
    delete ui;
}


void addnewaccount::onButtonCreateClicked()
{
    if(accountExist() == false)
    {
        setUserData();
        ui->label_8->setVisible(false);

        query.prepare("INSERT INTO User(firsName,lastName,email, password, username) "
                      "VALUES (:firsName, :lastName, :email, :password, :username)");
        query.bindValue(":firsName", this->firstName);
        query.bindValue(":lastName", this->lastName);
        query.bindValue(":email", this->email);
        query.bindValue(":password", this->password);
        query.bindValue(":username", this->userName);
        query.exec();
        ui->label_8->setText("<font color='Green'>Registered, exit and log in to your account </font>");
        ui->label_8->setVisible(true);
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(true);
        //this->close();
    }


}

bool addnewaccount::accountExist()
{

    this->email = ui->lineEdit_4->text();

    if (query.exec("select email from user"  ))
    {
        while (query.next())
        {
            if(this->email == query.value(0).toString()    )
            {
                this->emailExist = true;
                ui->label_8->setText("Account exist");
                ui->label_8->setVisible(true);
                break;

            }
            else if (ui->lineEdit_3->text() != ui->lineEdit_2->text())
            {
                ui->label_8->setText("Passwords don't match");
                ui->label_8->setVisible(true);
            }
            else if (ui->lineEdit->text().isEmpty() ||  ui->lineEdit_2->text().isEmpty() || ui->lineEdit_3->text().isEmpty() || ui->lineEdit_4->text().isEmpty() || ui->lineEdit_5->text().isEmpty() || ui->lineEdit_6->text().isEmpty() )
            {
                this->emailExist = true;
                ui->label_8->setText("Please fill the empty field");
                ui->label_8->setVisible(true);
                break;
            }
            else
            {
                ui->label_8->setVisible(false);
                this->emailExist = false;
            }

        }
    }
    else
    {
        qDebug() << "Błąd zapytania SQL: ";

    }
    return this->emailExist;

}

void addnewaccount::setUserData()
{
    this->userName  = ui->lineEdit->text();
    this->password  = ui->lineEdit_2->text();
    this->email     = ui->lineEdit_4->text();
    this->firstName = ui->lineEdit_5->text();
    this->lastName  = ui->lineEdit_6->text();
}
void addnewaccount::onButtonLogInClicked()
{
    this->close();
}
