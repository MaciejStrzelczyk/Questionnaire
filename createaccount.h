#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>
#include <QPushButton>
#include <QtSql>
#include <QtCore>
#include <QRadioButton>
#include <QObject>

namespace Ui {
class createAccount;
}

class createAccount : public QDialog
{
    Q_OBJECT

public:

    unsigned int id_user;
    QSqlDatabase db;
    explicit createAccount(QWidget *parent = nullptr);
    ~createAccount();
    void clickPushButton();
    bool getIsAutentication();


private:
    Ui::createAccount *ui;
    bool isAautentication = false;
    void connectToDataBase();

signals:
    void danePrzeslane(const QSqlQuery &dane, const QSqlDatabase &db);

private slots:
    void onButtonOkClicked();
    void onButton2Clicked();
    void clearLineEdit();

};

#endif // CREATEACCOUNT_H
