#ifndef ADMUPDATE_H
#define ADMUPDATE_H
#include "mainwindow.h"
#include "secwin.h"

#include <QDialog>

namespace Ui {
class admupdate;
}

class admupdate : public QDialog
{
    Q_OBJECT

public:
    explicit admupdate(QWidget *parent = nullptr);
    ~admupdate();
    QSqlQuery *query;
    MainWindow win;
    Inventory Ivt;

private slots:
    void on_Save_clicked();

private:
    Ui::admupdate *ui;
    QString manufact;
    QString qtysold;
    QString Product_name, price, amt;
};

#endif // ADMUPDATE_H
