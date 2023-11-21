#ifndef RECORD_H
#define RECORD_H

#include <QWidget>

#include "mainwindow.h"

namespace Ui {
class Record;
}

class Record : public QWidget
{
    Q_OBJECT

public:
    explicit Record(QWidget *parent = nullptr);
    ~Record();

private slots:
    void on_search_clicked();

private:
    Ui::Record *ui;
    MainWindow win;
    QSqlQuery *query;
};

#endif // RECORD_H
