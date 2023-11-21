#include "record.h"
#include "ui_record.h"
#include "mainwindow.h"


Record::Record(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Record)
{
    ui->setupUi(this);
}

Record::~Record()
{
    delete ui;
}

void Record::on_search_clicked()
{
    QString search = ui->record->text();
      QSqlQueryModel *model = new QSqlQueryModel();

   //  table.DatabaseConnect();
//      db = QSqlDatabase::addDatabase("QSQLITE");
//         db.setDatabaseName("admin.db");
        query = new QSqlQuery(win.db);


//     query = new QSqlQuery(db);

    if(search !=""  || search == "records"){

        query->prepare("select * from second");
        query->exec();

            model->setQuery(*query);
         ui->tableView->setModel(model);


          win. db.close();

         qDebug()<< (model->rowCount());
    }else{


        QMessageBox::information(this, "Query", "Wrong query, [hint] search name:[records]");
    }



}




