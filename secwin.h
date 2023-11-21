#ifndef SECWIN_H
#define SECWIN_H

#include <mainwindow.h>
#include <QMainWindow>
#include <QSqlQueryModel>
#include <QDialog>
#include <table.h>
#include <QTimer>

#include <QLabel>
#include "dialog.h"






namespace Ui {
class Inventory;
}


class Inventory : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inventory(QWidget *parent = nullptr);
    ~Inventory();
    QString category, tota_qty;
    bool loggedOut;
    qint32 avail_qty;
    QSqlQuery *query;
    MainWindow win;


//    Dialog dlg;




private slots:
//   void on_loadtable_clicked();

    void on_Search_clicked();

    void on_actionAdd_New_triggered();

    void on_Update_clicked();

    void on_actionOrder_triggered();

    void on_Deleat_clicked();

    void on_Reset_clicked();


    void updateTime();

    void on_actionlogout_triggered();

    void on_actionAboutus_triggered();

    void on_actionsave_triggered();

    void on_Save_clicked();

    void on_actionExit_2_triggered();

private:
    Ui::Inventory *ui;
    qint32 qtysold;
    QLabel *lb;
    QDateTime stmp;

//    QSqlQueryModel *model;

//    QSqlQuery *query;
//    QSqlQueryModel *model;
//    QSqlDatabase db;
};

#endif // SECWIN_H
