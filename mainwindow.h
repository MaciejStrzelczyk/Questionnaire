
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtCore>
#include <QPushButton>
#include <QRadioButton>
#include <QSqlDatabase>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void clickPushButton();
    void clickRadioButton();
    QSqlDatabase db;

public slots:
    void odebranoDane(const QString &dane, const QSqlDatabase &db);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
