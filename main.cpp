#include "mainwindow.h"
#include "createaccount.h"
#include <QApplication>
#include <QObject>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    createAccount *accountScrean = new createAccount();
    MainWindow *w = new MainWindow();
    QObject::connect(accountScrean, &createAccount::danePrzeslane, w, &MainWindow::odebranoDane);

    accountScrean->exec();
    w->show();

    return a.exec();
}
