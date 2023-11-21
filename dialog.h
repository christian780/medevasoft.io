#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSqlQueryModel>


#include "mainwindow.h"




namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT



public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    qint32 qres;
//    void  table_lookup();

     bool passed;
//    QSqlQuery *query;
//    QSqlDatabase db;




private slots:
    void on_Save_clicked();
    void insert();









//    void on_Load_clicked();

private:
    Ui::Dialog *ui;
    qint32 qtysold;
    QTime *tm;
    QDate *dt;
    QSqlQuery* query;
    QString prodct_name;
    bool status;



};

#endif // DIALOG_H
