
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtCore>
#include <QPushButton>
#include <QRadioButton>
#include <QSqlDatabase>
#include <QtWidgets>
#include <QAction>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void clickRadioButton();


public slots:
    void odebranoDane(const QSqlQuery &dane, const QSqlDatabase &db);

private slots:
    void on_actionExit_triggered();
    //void on_actionDodaj_triggered();
    void clickPushButton5();
    void clickPushButton2();
    void clickPushButton4();
    void clickPushButton6();

    void on_actionAdd_triggered();

private:
    Ui::MainWindow *ui;
    QString idUser;
    QString userName;
    QString sex;
    QSqlDatabase db;
    QSqlQuery data;


};

#endif // MAINWINDOW_H
