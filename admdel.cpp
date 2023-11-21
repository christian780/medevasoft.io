#include "admdel.h"
#include "ui_admdel.h"
#include "mainwindow.h"
#include "globals.h"


admdel::admdel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admdel)
{
    ui->setupUi(this);
}

admdel::~admdel()
{
    delete ui;
}

void admdel::on_Save_clicked()
{
//    MainWindow win;

    QString Product_name, manufact, desc, cateprice, Qty,  Produ_id, cate, price;
    qint32 qty_sold;
     query = new QSqlQuery(db);


//    Produ_id =ui->id_label->text();
    price = ui->price_label->text();
    Qty = ui->Qty_label->text();
    desc = ui->description->text();
    Product_name = ui->product_label->text();
    manufact = ui->Manufact_label->text();
    cate = ui->cat_label->text();
//    qty_sold = ui->Qty_Sold_2->text().toInt();




    query->prepare("DELETE FROM Item WHERE Product_Name='"+Product_name+"'");

//    win.query->bindValue(":Product_ID", Produ_id);
    query->bindValue(":Product_Name",Product_name);
    query->bindValue(":Manufacture", manufact);
    query->bindValue(":Price", price);
    query->bindValue(":total_qty", Qty);
    query->bindValue(":Product_desc", desc);
    query->bindValue(":category", cate);
    query->bindValue(":Price", price);
//    win.query->bindValue(":Qty_Sold", qty_sold );

    if(query->exec()){

        QMessageBox::information(this, "DELETE", "Record Deleted successfully");


    }
    else{

        QMessageBox::critical(this, "DELETE",query->lastError().text());


    }

 //  delete model;
}



