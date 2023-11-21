#ifndef TABLE_H
#define TABLE_H

#include "mainwindow.h"

#include <QWidget>

namespace Ui {
class Table;
}

class Table : public QWidget
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    ~Table();
    QSqlQuery *query;
//    QSqlDatabase db;
     MainWindow win;


private slots:
    void on_Save_clicked();

private:
    Ui::Table *ui;
};

#endif // TABLE_H
