#include "load.h"
#include "ui_load.h"
#include <QSqlQueryModel>
#include "mainwindow.h"
#include "globals.h"


Load::Load(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Load)
{
    ui->setupUi(this);
     ui->search_3->setPlaceholderText("Search");
}

Load::~Load()
{
    delete ui;
}



void Load::on_Save_clicked()
{
     QString search = ui->search_3->text();
       QSqlQueryModel *model = new QSqlQueryModel();

    //  table.DatabaseConnect();
 //      db = QSqlDatabase::addDatabase("QSQLITE");
//         db.setDatabaseName("admin.db");
         query = new QSqlQuery(win.db);


//     query = new QSqlQuery(db);

     if(search !=""  || search == "items"){
         query->prepare("select * from Item");
         query->exec();

             model->setQuery(*query);
          ui->tableView->setModel(model);


           win. db.close();

          qDebug()<< (model->rowCount());
     }else{


         QMessageBox::information(this, "Query", "Wrong query, [hint] search name:[items]");
     }



}
