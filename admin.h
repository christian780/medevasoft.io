#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include <QFrame>
#include <QTimer>

#include "secwin.h"

namespace Ui {
class Admin;
}
class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
    Inventory invt;
    qint32 total_qty, previous;
    qint32  avail_qty;
    qint32  price,total;
    bool loggedOut;
//    QSqlDatabase db;
    QSqlQuery *query;
    MainWindow wn;







private slots:
    void on_addinvt_clicked();
    void updateTime();

    void on_Search_clicked();

    void on_actionview_triggered();

    void on_actionexit_triggered();

    void on_Update_2_clicked();

    void on_Update_4_clicked();

    void on_Records_triggered();

private:
    Ui::Admin *ui;
    qint32 qtysold;
    qint32 amt_sold;


};

#endif // ADMIN_H
