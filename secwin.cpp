#include "secwin.h"
#include "ui_secwin.h"
#include "ui_table.h"
#include "ui_dialog.h"
#include "dialog.h"
#include "delete.h"
#include "aboutus.h"
#include "db.h"
#include "admin.h"
#include "globals.h"

#include <qsqlrecord.h>
#include <QDateTimeEdit>
#include<QJsonObject>
#include <stdlib.h>


//using query::Query;
//using query::db;


Inventory::Inventory(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Inventory)
{




    ui->setupUi(this);
    MainWindow wn;

    ui->search->setPlaceholderText("Search");


//    QSqlQueryModel *model = new QSqlQueryModel(this);
 //   QSqlQuery* query = new QSqlQuery(wn.db);



    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);

//    Dialog dlg;
//    connect(&dlg, SIGNAL(Dailog()), this, SLOT(on_Search_clicked()));


//    model->setQuery(*query);
//     ui->tableView->setModel(model);
//     delete model;

  //  ui->lineEdit->setPlaceholderText("Enter user name");


}

Inventory::~Inventory()
{
    delete ui;
}

/*void Inventory::on_loadtable_clicked()
{

   QSqlQueryModel *model = new QSqlQueryModel();
    MainWindow table;
    table.DatabaseConnect();
    QSqlQuery* query = new QSqlQuery(table.db);

    query->prepare("select * from users");
    query->exec();

    model->setQuery(*query);
   ui-> tableView->setModel(model);

   table.db.close();

   qDebug() << (model->rowCount());



    //db.open();
   // MainWindow.db.open();

}*/



void Inventory::on_Search_clicked()
{


    QString search = ui->search->text();
    QSqlQueryModel *model = new QSqlQueryModel();
     query = new QSqlQuery(win.db);
    QString str;
//    QList<QVariant> list;
//    QSqlRecord rec;
     qint32 price, total_qty, total;
    qint32  previous;




//    query->prepare("select * from Item");
    if(search !=""){
    query->prepare(QString("SELECT *  FROM Item WHERE Product_Name = '"+search+"'"));
    query->bindValue(":Product_Name", search);



    if(query->exec()){

        while(query->next()){

            total_qty = query->value(2).toInt();
             price= query->value(5).toInt();
             qtysold = query->value(6).toInt();


          ui->search->setText(query->value(0).toString());


     }

 //       qDebug()<< price << qty ;
         qDebug()<<qty_sold << prod_name;
 //         previous = qty_sold;
         stmp = QDateTime::currentDateTime();
         total = price * total_qty;
           avail_qty = total_qty - qtysold;
           ui->result_label->setText(QString::number(avail_qty));

            ui->Amount->setText(QString("N%L1").arg(total, 0));
             ui->qty_sold->setText(QString::number(qty_sold));
             QString dateTimesting = stmp.toString("yyyy-MM-dd/hh-mm-ss");
             ui->Time_edt->setText(dateTimesting);






          model->setQuery(*query);
         ui->tableView->setModel(model);




}
    else{
         QMessageBox::warning(this, "Query", query->lastError().text());


    }

 }
    else{

         QMessageBox::information(this, "Query", "Wrong query");
    }








//    QString q = "SELECT [Product_ID], [Product_Name], [Manufacture], [Qty], [Product_desc], [category], [Price]  FROM [Item] WHERE Product_ID= '"+search+"'";
//         query->exec(q);

}





void Inventory::on_actionAdd_New_triggered()
{
//  Ui::Table *tab   = new Ui::Table;
 Table  *table= new Table();
 table->show();

}


void Inventory::on_Update_clicked()
{

    Dialog *diag = new Dialog();
    diag->show();
}


void Inventory::on_actionOrder_triggered()
{

    Table  *table= new Table();
    table->show();
}


void Inventory::on_Deleat_clicked()
{
    Delete *del = new Delete();
    del->show();


}

/*   QSqlQueryModel *model = new QSqlQueryModel();
        MainWindow table;
       table.DatabaseConnect();
        QSqlQuery* query = new QSqlQuery(table.db);

        query->prepare("select * from Item");
        query->exec();

        model->setQuery(*query);
       ui->tableView->setModel(model);


       table.db.close();

       qDebug() << (model->rowCount());
   */

void Inventory::on_Reset_clicked()
{
    QMessageBox::information(this, "RESET", "database cache purged successfully");

}



void Inventory::updateTime(){

    MainWindow tablet;
    QDateTime stamp;
    stamp = QDateTime::currentDateTime();
    QString dateTimesting = stamp.toString("yyyy-MM-dd/hh-mm-ss");

    stamp = QDateTime::currentDateTime();

    ui->Timestamp->setText(dateTimesting);

}




void Inventory::on_actionlogout_triggered()
{

 //   MainWindow wn;
    if(QMessageBox::Yes == QMessageBox(QMessageBox::Question,
                                           "Login System", "Are you sure you want to logout?",
                                           QMessageBox::Yes|QMessageBox::No).exec())
        {
            this->loggedOut = true;
            this->hide();



        MainWindow *adb = new MainWindow();
        adb->show();

//            ui->passwordBox->setText("");
 //           ui->loginLabel->setText("You signed out!");
 //           ui->winStack->setCurrentIndex(0);
        }
}




void Inventory::on_actionAboutus_triggered()
{
    Aboutus *abt = new Aboutus();
    abt->show();


}


void Inventory::on_actionsave_triggered()
{
    QMessageBox::information(this, "Save", "database Saved successfully");

}


void Inventory::on_Save_clicked()
{
    QMessageBox::information(this, "Save", "database Saved successfully");


}




/*MainWindow win3;
QString search;

search = ui->search->text();
model = new QSqlQueryModel();
 query =  new QSqlQuery(win3.db);

 qint32 price, total_qty, total;


//    query->prepare("select * from Item");
if(search !=""){
query->prepare(QString("SELECT *  FROM Item WHERE Product_Name = '"+search+"'"));
query->bindValue(":Product_Name",search);



if(query->exec()){

    while(query->next()){

        total_qty = query->value(2).toInt();
         price= query->value(5).toInt();
//           qty_sold = query.value(6).toInt();


      ui->search->setText(query->value(0).toString());
//          ui->qty_sold->setText(QString::number(dlg.qty_sold));


 }
     total = price * total_qty;
       avail_qty = total_qty - qty_sold;
       ui->result_label->setText(QString::number(avail_qty));
//     qDebug()<<qty_sold << product_name;
       ui->qty_sold->setText(QString::number(qty_sold));
        ui->Amount->setText(QString("N%L1").arg(total, 0));

       if(qty_sold < WRONG_INPUT){
//            ui->result_label->setText(QString::number(original));
//            ui->Amount->setText(QString("N%L1").arg(total, 0));
         return;
    }
       else{

//             ui->Amount->setText(QString::number(total));
           ui->result_label->setText(QString::number(avail_qty));

     }




     model->setQuery(*query);
     ui->tableView->setModel(model);
      qDebug() << (model->rowCount());

}
else{
     QMessageBox::warning(this, "Query", query->lastError().text());


}

}
else{

    QMessageBox::information(this, "Query", "Wrong query");
}


//    QString q = "SELECT [Product_ID], [Product_Name], [Manufacture], [Qty], [Product_desc], [category], [Price]  FROM [Item] WHERE Product_ID= '"+search+"'";
//         query->exec(q);

}
*/

void Inventory::on_actionExit_2_triggered()
{
    if(QMessageBox::Yes == QMessageBox(QMessageBox::Question,"Exit", "Are you sure you want to exit?",
                                           QMessageBox::Yes|QMessageBox::No).exec())
    {

        this->loggedOut = true;
        exit(EXIT_SUCCESS);
    }


}

