#ifndef DELETE_H
#define DELETE_H

#include <QDialog>
#include <QSqlQueryModel>

#include "mainwindow.h"


namespace Ui {
class Delete;
}

class Delete : public QDialog
{
    Q_OBJECT

public:
    explicit Delete(QWidget *parent = nullptr);
    ~Delete();
    QSqlQuery *query;
     MainWindow win;

private slots:
    void on_Save_clicked();

private:
    Ui::Delete *ui;
    QString amtsold;
};

#endif // DELETE_H
