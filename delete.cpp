#include "delete.h"
#include "ui_delete.h"
#include "globals.h"
#include "mainwindow.h"


Delete::Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
}

Delete::~Delete()
{
    delete ui;
}

void Delete::on_Save_clicked()
{
//    MainWindow win4;
    QString Product_name, manufact, desc, cateprice, Qty,  Produ_id, cate, price;
    QString qtysold, total_qty;
//    db = QSqlDatabase::addDatabase("QSQLITE");
 //     db.setDatabaseName("admin.db");
      query = new QSqlQuery(win.db);



//    Produ_id =ui->id_label->text();
    price = ui->price_edt->text();
   qtysold  = ui->Qty_edit->text();
    desc = ui->Prdct_desc_edt->text();
    Product_name = ui->product_label->text();
    manufact = ui->manufact_edt->text();
    cate = ui->cat_edt->text();
   total_qty  = ui->total_edt->text();
   amtsold = ui->Amt_edit->text();


//     MainWindow win;


    query->prepare("DELETE FROM Item WHERE Product_ID='"+Product_name+"'");

/*   win.query->bindValue(":Product_ID", Produ_id);
    query->bindValue(":Product_Name",Product_name);
    query->bindValue(":Manufacture", manufact);
    query->bindValue(":Price", price);
    query->bindValue(":total_qty", total_qty);
    query->bindValue(":Product_desc", desc);
      query->bindValue(":category", cate);
     query->bindValue(":Price", price);
    query->bindValue(":Qty_Sold", qtysold );
    query->bindValue(":Amt_sold", amtsold );
*/
    if(query->exec()){

        QMessageBox::information(this, "DELETE", "Record Deleted successfully");


    }
    else{

        QMessageBox::critical(this, "DELETE", query->lastError().text());


    }

 //  delete model;
}

