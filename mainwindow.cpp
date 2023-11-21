#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "secwin.h"
#include <QtGui>
#include <admin.h>
#include <QMainWindow>
#include <QCoreApplication>
#include "globals.h"
#include "db.h"


#define path_to_DB  "C:/IVT/projct/admin.db"

//QSqlDatabase db;
//QSqlQuery *query;


//constexpr Value LazyThreshold  = Value(1400);
//constexpr Value SpaceThreshold = Value(12222);

MainWindow::MainWindow(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    QDir dbDir;


    QTemporaryDir tmp;
    QString path = QCoreApplication::applicationFilePath();
//    QString db_path = QDir(tmp.path()).absoluteFilePath(QString("QSQLITE") + ".db");
//    qDebug()<< db_path;
 //  QString db1 = db_path + QString("");

  db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("admin.db");
    query = new QSqlQuery(db);




 //   auto value = ((10<=20) > 0);


    QPixmap pix("C:/IVT/images/invt.png");
       int w = ui->label_3->width();
       int h = ui->label_3->height();

     // ui->comboBox->
    ui->label_3->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));

    ui->lineEdit->setPlaceholderText("Enter user name");
    ui->lineEdit_2->setPlaceholderText("Enter password");
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
//    Admin2 *adm = new Admin2();

//     connect(adm, SIGNAL(timeout()), this, SLOT(login()));


       if(!db.open()){

           qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
   }
       else{

                qDebug()<< "database connected";
       }





    //Database conect
//     DatabaseConnect();
 //   DatabaseInit();



}

MainWindow::~MainWindow()
{
    delete ui;
    qDebug()<< "closing connection to databse" ;
//   db.close();
}



/*void MainWindow::DatabaseConnect()
{
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
   QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
   db.setDatabaseName(path_to_DB);


        if(!db.open())
            qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
    }
    else
        qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << DRIVER << " available";
}

*/

/*void MainWindow::DatabaseInit()
{

 //   QString querystr("CREATE TABLE people (id INTEGER PRIMARY KEY, name TEXT)");
    query = QSqlQuery();

  //  QSqlQuery(const QString& query = QString(), QSqlDatabase db = QSqlDatabase())
   query.exec("INSERT INTO employee (id, name, salary" "VALUES (100, 'Thad Beamout', 56666");
//  QVariantList names;

    if(query.execBatch())
        qWarning() << "MainWindow::DatabaseInit - ERROR: " << query.lastError().text();

}*/



void MainWindow::on_pushButton_clicked(){

    QString username = ui->lineEdit->text();
     QString password = ui->lineEdit_2->text();


     this->loggedin = Login(username, password);


     if(username == "admin" && password == "admin"){

         this->hide();
         Admin *adm = new Admin();
         adm->show();
     }
     else if (this->loggedin){

             this->hide();
             Inventory *inv = new Inventory();
             inv->show();
             inv->menuBar();
     }






/*   if(username == "test" && password == "test"){

        this->hide();
        Inventory *inv = new Inventory();
        inv->show();
        inv->menuBar();

    }
*/

}



bool MainWindow::Login(QString u, QString p){

//    ui->adminButton->setVisible(false);



        exists = false;





      QSqlQuery checkQuery(db);
      checkQuery.prepare("SELECT * FROM Users WHERE username = (:username) AND password = (:password)");
      checkQuery.bindValue(":username", u);
      checkQuery.bindValue(":password", p);

      if (checkQuery.exec())
      {
          if (checkQuery.next())
          {
              exists = true;
          }
      }

      return exists;

}

/*
        QString username = ui->lineEdit->text();
        QString password = ui->lineEdit_2->text();


//      query->prepare("INSERT INTO Users (username, password)" "VALUES (:username, :password)");
        query->prepare(QString("SELECT  * FROM Users WHERE username =:username AND password = :password"));
      query->bindValue(":username", username);
       query->bindValue(":password", password);
        if (query->exec())
        {


                // You login a user here
                QString name = query->value(0).toString();
                QString password = query->value(1).toString();

                this->hide();
                Inventory *inv = new Inventory();
                inv->show();
                inv->menuBar();

                qDebug() << name << password << "is logged in";
            }
            else
            {
                 QMessageBox::warning(this, "Login", "Username and password incorrect");
            }
        }


*/


/*if(username =="admin" && password =="admin"){


    QFileInfo checkfile(path_to_DB);


    if(checkfile.isFile()){


        if(!db.open()){

            qDebug()<< __FUNCTION__<<" ERROR: could not establish destination storage:" <<db.lastError().text();

        }

    }

    db.setDatabaseName(path_to_DB);
    db.setPassword(password);
    db.setUserName(username);

    QSqlQuery query;

    if(query.prepare("SELECT username, password, FROM users WHERE username='" + username + "' password='" + password + "\'")){

        if(query.exec()){

           QString msg;
           msg = "Username = " + query.value(0).toString() + "\n" +
                   "password =" + query.value((1)).toString();

           QMessageBox::information(this,  "Connected succesfully", msg);



        }
    }


    this->hide();
    Inventory *inv = new Inventory();
    inv->show();
    inv->menuBar();
}
else{

       if(query.exec("SELECT id, username, password, FROM users WHERE username='" + username + "' password='" + password + "\'")){

           int cnt = 0;

           while(query.next()){

              cnt++;

           }
           if(cnt==1){

               this->hide();
               Inventory *inv = new Inventory();
               inv->show();
               inv->menuBar();
           }
       }


    QMessageBox::warning(this, "Login", "Username and password incorrect");
 }





}*/



/*void MainWindow::login(){

    this->username = ui->lineEdit->text();
    this->passwrd = ui->lineEdit_2->text();


    query->prepare(QString("SELECT  * FROM Users WHERE username =:username AND password = :password"));

    query->bindValue(":username", username);
    query->bindValue(":password", passwrd);

    if(!query->exec()){

         QMessageBox::warning(this, "query", "Failed to execute");
    }
    else{

        if(query->first()){

            QString name = query->value(1).toString();
            QString passwordfromdb = query->value(2).toString();

            if(name == username && passwordfromdb == passwrd){

                this->hide();
                Admin *adm = new Admin();
                adm->show();

            }


        }
    }



}

*/
/*QString username = ui->lineEdit->text();
 QString password = ui->lineEdit_2->text();

 query->prepare(QString("SELECT  * FROM Users WHERE username =:username AND password = :password"));

    query->bindValue(":username", username);
    query->bindValue(":password", password);

    if(!query->exec()){

             QMessageBox::warning(this, "query", "Failed to execute");
    }
    else{

             while(query->next()){

                 QString name = query->value(1).toString();
                 QString passwordfromdb = query->value(2).toString();


                 if(name == "admin" && passwordfromdb =="admin"){

     //                qDebug()<< "hello..";
                      this->hide();
                     Admin *adb = new Admin();
                     adb->show();
                   }else if(name == username && passwordfromdb == password){

                     this->hide();
                     Inventory *inv = new Inventory();
                     inv->show();
                     inv->menuBar();
                 }
                 else{

                     QMessageBox::warning(this, "Login", "Username and password incorrect");
                 }
             }
         }
*/






