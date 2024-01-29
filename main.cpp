#include "mainwindow.h"
#include "createaccount.h"
#include <QApplication>
#include <QObject>
#include <QMessageBox>
#include <QString>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int i = 0;
    createAccount *accountScrean = new createAccount();
    MainWindow *w = new MainWindow();
    QObject::connect(accountScrean, &createAccount::danePrzeslane, w, &MainWindow::odebranoDane);

    do
    {
        accountScrean->exec();
        i++;
    }
    while(accountScrean->getIsAutentication() == false && i < 3 );

    if(accountScrean->getIsAutentication() == false)
    {
        QMessageBox msgBox;
        msgBox.setText("Podano błędnie zbyt wiele razy dane logowania");
        msgBox.exec();
        delete accountScrean;
        delete w;
    }
    else
    {
        w->show();
        return a.exec();
    }


}
