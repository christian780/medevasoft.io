#include "admupdate.h"
#include "ui_admupdate.h"
#include "globals.h"
#include "mainwindow.h"

admupdate::admupdate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admupdate)
{
    ui->setupUi(this);

//    db = QSqlDatabase::addDatabase("QSQLITE");
//      db.setDatabaseName("admin.db");
//      query = new QSqlQuery(db);

}

admupdate::~admupdate()
{
    delete ui;
}

void admupdate::on_Save_clicked()
{
//     MainWindow win;
//   QString prod_name = ui->Name_label->text();
//    QSqlQueryModel *model = new QSqlQueryModel();


   QString  serialnum, Product_desc, Product_cate;
   qint32 serial_number, Produ_id;

    query = new QSqlQuery(win.db);

//    Produ_id = ui->Product_label->text().toInt();
   Ivt.category = ui->price_edit->text();
   Ivt.tota_qty = ui->Total_edit->text();
   Product_name = ui->Name_label->text();
   manufact = ui->manufact_edit->text();
   Product_desc = ui->desc_edit->text();
   Product_cate = ui->Cat_edit->text();
   qtysold= ui->Qty_edit->text();
   price = ui->price_edit->text();
   amt = ui->Amtedit->text();






//    QSqlQuery* query = new QSqlQuery(win.db);

   query->prepare("UPDATE Item SET Product_Name='"+Product_name+"', Manufacture='"+manufact+"', total_qty='"+ Ivt.tota_qty+"', Product_desc='"+Product_desc+"', category='"+Product_cate+"', Price='"+price+"', Qty_Sold='"+qtysold+"', Amt_sold='"+amt+"'  WHERE Product_Name = '"+Product_name+"'");
//    "create table if not exists ACCOUNTS_PAYABLE (`Entry Number` INTEGER PRIMARY KEY AUTOINCREMENT DEFAULT 1)";


//    win.query->bindValue(":Product_ID", Produ_id);
     query->bindValue(":Product_Name",Product_name);
    query->bindValue(":Manufacture", manufact);
    query->bindValue(":total_qty", Ivt.tota_qty);
    query->bindValue(":Product_desc",  Product_desc);
      query->bindValue(":category",  Product_cate);
    query->bindValue(":Price",price );
    query->bindValue(":Qty_Sold", qtysold);
    query->bindValue(":Amt_sold", amt);




   if(query->exec()){

       QMessageBox::information(this, "UPDATE", "Table updated successfully");
//       recipt.num_of_items = qty_sold;




   }
   else{

       QMessageBox::critical(this, "UPDATE",query->lastError().text());


   }

//  delete model;



}

