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

private:
    Ui::createAccount *ui;

signals:
    void danePrzeslane(const QString &dane, const QSqlDatabase &db);

private slots:
    void onButtonOkClicked();

};

#endif // CREATEACCOUNT_H
