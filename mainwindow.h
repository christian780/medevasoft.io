#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dialog.h"

#include <QMainWindow>
#include <QtSql/QSqlQuery>
//#include <sqlite3.h>
#include <QMessageBox>
#include <QFileInfo>
#include <QItemSelectionModel>
#include <QTime>
#include <QDate>
#include <QVector>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow :  public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     QItemSelectionModel *secmodel;
     QString search;
    QSqlQuery *query;
     QSqlDatabase db;
     bool Login(QString u, QString p);









// void DatabaseConnect();

// void DatabaseInit();



private slots:
    void on_pushButton_clicked();
//     void login();


//   QSqlDatabase connect();

//void DatabaseConnect();

//    void DatabasePopulate();


private:

    QString username, passwrd;
     Ui::MainWindow *ui;
     bool loggedin, exists;




};
#endif // MAINWINDOW_H
