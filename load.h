#ifndef LOAD_H
#define LOAD_H
#include "mainwindow.h"

#include <QDialog>

namespace Ui {
class Load;
}

class Load : public QDialog
{
    Q_OBJECT

public:
    explicit Load(QWidget *parent = nullptr);
    ~Load();
    QSqlQuery *query;
      MainWindow win;

private slots:
    void on_Save_clicked();

private:
    Ui::Load *ui;
};

#endif // LOAD_H
