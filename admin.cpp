#include "admin.h"
#include "ui_admin.h"
#include "table.h"
#include "secwin.h"
#include "load.h"
#include "dialog.h"
#include "admupdate.h"
#include "admdel.h"
#include "globals.h"
#include "mainwindow.h"
#include "record.h"


#include <QMessageBox>
#include <QSqlRecord>
#include <QHBoxLayout>


Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

   MainWindow wn;


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);



   ui->search_2->setPlaceholderText("Search");


   QSqlQueryModel *model = new QSqlQueryModel(this);
   QSqlQuery* query = new QSqlQuery(wn.db);



   model->setQuery(*query);
    ui->tableView->setModel(model);
//    delete model;
}

Admin::~Admin()
{

    delete ui;
}

void Admin::on_addinvt_clicked()
{
    Table  *table= new Table();
    table->show();
}

void Admin::updateTime(){


    QDateTime stamp;
    stamp = QDateTime::currentDateTime();
    QString dateTimesting = stamp.toString("yyyy-MM-dd/hh-mm-ss");

    ui->Timestamp->setText(dateTimesting);

}


void Admin::on_Search_clicked(){


    QString search = ui->search_2->text();
    QSqlQueryModel *model = new QSqlQueryModel();
     query = new QSqlQuery(wn.db);
    QString str;
    QList<QVariant> list;
    QSqlRecord rec;
//     qint32 price, total_qty, total;
    qint32  previous, profit;





//    query->prepare("select * from Item");
    if(search !=""){
    query->prepare(QString("SELECT *  FROM Item WHERE Product_Name = '"+search+"'"));
    query->bindValue(":Product_Name", search);



    if(query->exec()){

        while(query->next()){

            total_qty = query->value(2).toInt();
             price= query->value(5).toInt();
              qtysold = query->value(6).toInt();
             amt_sold = query->value(7).toInt();



          ui->search_2->setText(query->value(0).toString());


     }

 //       qDebug()<< price << qty ;
//          previous = qty_sold;
         total = price * total_qty;
           avail_qty = total_qty - qty_sold;
           profit = amt_sold * qtysold;
           ui->Label_qty->setText(QString::number(avail_qty));

            ui->Amount->setText(QString("N%L1").arg(total, 0));
            ui->qty_edit->setText(QString::number(qty_sold));
            ui->proft_edit->setText(QString("N%L1").arg(profit, 0));





//               ui->Amount->setText(QString::number(total));







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



void Admin::on_actionview_triggered()
{
   Load* ld = new Load();
   ld->show();
}


void Admin::on_actionexit_triggered()
{
    if(QMessageBox::Yes == QMessageBox(QMessageBox::Question,
                                           "Login System", "Are you sure you want to logout?",
                                           QMessageBox::Yes|QMessageBox::No).exec())
        {
            this->loggedOut = true;
            this->hide();
             Inventory *in = new Inventory();
             in->show();
        }
}


void Admin::on_Update_2_clicked()
{

    admupdate *update = new admupdate();
    update->show();


 /*   QString stysheet("background-color: qconicalgradient(cx:0.548913, cy:1, angle:0, stop:0 rgba(0, 0, 103, 255), stop:1 rgba(255, 255, 255, 255)");
    QLabel *lbl = new QLabel();
    QDialog *dlg = new QDialog();
    QHBoxLayout *hbx = new  QHBoxLayout();


    lbl->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    lbl->setText("xty");
    lbl->setAlignment()
    lbl->show();


    dlg->setGeometry(650, 487, 660, 487);
    dlg->setStyleSheet("background-color: qconicalgradient(cx:0.548913, cy:1, angle:0, stop:0 rgba(0, 0, 103, 255), stop:1 rgba(255, 255, 255, 255))");
    dlg->setWindowTitle("Update");
    hbx->addWidget(lbl);
     dlg->setLayout(hbx);




    dlg->show();
    this->setWindowFlag(Qt::Dialog);
*/

}


void Admin::on_Update_4_clicked()
{
    admdel *adex = new admdel();
    adex->show();


}


void Admin::on_Records_triggered()
{
    Record *rec = new Record();
    rec->show();
}

