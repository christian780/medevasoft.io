#include "table.h"
#include "ui_table.h"
#include "secwin.h"
#include "globals.h"
#include "mainwindow.h"

#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>


Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    std::atomic<long> x{0};
    x.store(1, (std::memory_order_release));


}

Table::~Table()
{
    delete ui;
}

void Table::on_Save_clicked()
{
//    MainWindow win4;

    QString Product_name, desc, manufact;
    QString  serialnum;
    qint32 serial_number, Produ_id, cost,price, quantity_sold, amount_sold;
    Inventory Ivt;
//    db = QSqlDatabase::addDatabase("QSQLITE");
//      db.setDatabaseName("admin.db");
      query = new QSqlQuery(win.db);
 //   query = new QSqlQuery(db);

//    Produ_id = ui->Product_label->text().toInt();
      Product_name = ui->Name_edit->text();
      manufact = ui->Manufac_edit->text();
      Ivt.tota_qty = ui->totalqty_edit->text();
      desc  = ui->desc_edt->text();
      Ivt.category = ui->cat_edit->text();
      price = ui->Price_edit->text().toInt();
      quantity_sold =ui->qtysold_edit->text().toInt();
      amount_sold = ui->amount_edit->text().toInt();



//    manufact = ui->Manufacture_label->text();

//    Product_cate = ui->Cat_label->text();
//    Amount_sold = ui->Amount_sold->text().toInt();
//    qty_sold = ui->Qty_Sold->text().toInt();



//  query->prepare("INSERT INTO Users (username, password)" "VALUES (:username, :password)");

    query->prepare("INSERT INTO Item (Product_Name, Manufacture, total_qty, Product_desc, category, Price, Qty_sold, Amt_sold)" "VALUES (:Product_Name,  :Manufacture,  :total_qty, :Product_desc, :category, :Price, :Qty_sold,  :Amt_sold)");

//    win.query->bindValue(":Product_ID", Produ_id);
     query->bindValue(":Product_Name",Product_name);
     query->bindValue(":Manufacture", manufact);
     query->bindValue(":category",Ivt.category);
     query->bindValue(":total_qty", Ivt.tota_qty);
     query->bindValue(":Product_desc", desc);
     query->bindValue(":category", Ivt.category);
     query->bindValue(":Price", price);
     query->bindValue(":Qty_sold",quantity_sold);
     query->bindValue(":Amt_sold",amount_sold);



//    query->bindValue(":Amount", Amount_sold);


     if(query->exec()){

         QMessageBox::information(this, "Add", "Table added successfully");


     }
     else{

         QMessageBox::critical(this, "Add",query->lastError().text());


     }




}

