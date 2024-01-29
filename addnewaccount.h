#ifndef ADDNEWACCOUNT_H
#define ADDNEWACCOUNT_H

#include <QDialog>
#include <QDebug>
#include <QSqlQuery>

namespace Ui {
class addnewaccount;
}

class addnewaccount : public QDialog
{
    Q_OBJECT

public:
    explicit addnewaccount(QWidget *parent = nullptr);
    ~addnewaccount();

private:
    Ui::addnewaccount *ui;
    QString firstName;
    QString lastName;
    QString email;
    QString userName;
    QString password;
    QSqlQuery query;
    void setUserData();
    bool emailExist = true;
    bool accountExist();
    void onButtonCreateClicked();
    void onButtonLogInClicked();
};

#endif // ADDNEWACCOUNT_H
