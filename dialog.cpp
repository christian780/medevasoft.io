#include "dialog.h"
#include "ui_dialog.h"
#include <QVector>
#include <QDate>
#include <QTime>
#include "globals.h"


#include "mainwindow.h"



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)

{

       ui->setupUi(this);
    connect(ui->Save, &QPushButton::clicked, this, &Dialog::on_Save_clicked);
    connect(this, &Dialog::on_Save_clicked, this, &Dialog::insert);

//    db = QSqlDatabase::addDatabase("QSQLITE");
//      db.setDatabaseName("admin.db");
//      query = new QSqlQuery(db);


}

Dialog::~Dialog()
{
    delete ui;
}

 QString prod_name;

 qint32 amount;
qint32  qty_sold;

QDate date_sold;
QTime time_sold;
qint32 amount_sold;
int  qty_sold_new;

void Dialog::on_Save_clicked()
{
 //   MainWindow win2;
      MainWindow win;



//    QSqlQueryModel *model = new QSqlQueryModel();
    QString  manufact, desc, cateprice, cate, price, Qty;




 //   Produ_id =ui->id_label->text().toInt();
//    price = ui->price_label->text();
//      Qty = ui->Qty_label->text();
//    desc = ui->description->text();
    prodct_name  = ui->Product_label->text();
//    manufact = ui->Manufact_label->text();
 //    cate = ui->cat_label->text();
     qty_sold  = ui->Qty_Sold->text().toInt();
     amount = ui->Amt_edit->text().toInt();
//    qDebug() << Product_name << qty_sold;


     prod_name = prodct_name;
     date_sold =dt->currentDate();
     time_sold =tm->currentTime();
     amount_sold = amount;
     qty_sold_new = qty_sold;
//     QMessageBox::information(this, "UPDATE", "registerd");

     emit  insert();

    query = new QSqlQuery(win.db);


    query->prepare("UPDATE Item  SET Product_Name ='"+prodct_name+"', Qty_Sold='"+QString::number(qty_sold)+"', Amt_sold='"+QString::number(amount)+"'  WHERE Product_Name='"+prodct_name+"' ");
//    "create table if not exists ACCOUNTS_PAYABLE (`Entry Number` INTEGER PRIMARY KEY AUTOINCREMENT DEFAULT 1)";


//    win.query->bindValue(":Product_ID", Produ_id);
      query->bindValue(":Product_Name",prodct_name);
//    win.query->bindValue(":Manufacture", manufact);
//    win.query->bindValue(":Price", price);
//    win.query->bindValue(":Qty", Qty);
//    win.query->bindValue(":Product_desc", desc);
//    win.query->bindValue(":category", cate);
     query->bindValue(":Amt_sold", amount);
     query->bindValue(":Qty_Sold", qty_sold);


    if(query->exec()){

        QMessageBox::information(this, "UPDATE", "Table updated successfully");



    }
    else{

        QMessageBox::critical(this, "UPDATE", query->lastError().text());


    }

//  delete model;

}

void Dialog::insert(){

    bool status = true;
    MainWindow win;

      QSqlQuery* query = new QSqlQuery(win.db);

     query->prepare("INSERT INTO second(product, amount,  Qtysold, date, time)" "VALUES(:product, :amount, :Qtysold, :date, :time)");


       query->bindValue(":product", prod_name);
      query->bindValue(":amount", amount_sold);
      query->bindValue(":Qtysold",qty_sold_new);
      query->bindValue(":date",date_sold);
      query->bindValue(":time", time_sold);


    if(query->exec()){

        QMessageBox::information(this, "Item", "Items registered successfully");

    }
    else{

        QMessageBox::critical(this, "Table", query->lastError().text());


    }


}


/*namespace Search {

  receipt rcpts;
}

*/
