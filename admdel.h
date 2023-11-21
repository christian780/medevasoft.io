#ifndef ADMDEL_H
#define ADMDEL_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class admdel;
}

class admdel : public QDialog
{
    Q_OBJECT

public:
    explicit admdel(QWidget *parent = nullptr);
    ~admdel();
    QSqlQuery *query;
     QSqlDatabase db;


private slots:
    void on_Save_clicked();

private:
    Ui::admdel *ui;
};

#endif // ADMDEL_H
