#include "aboutus.h"
#include "ui_aboutus.h"
#include <QPushButton>
#include <QDialog>



Aboutus::Aboutus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aboutus)
{
    ui->setupUi(this);



//    connect(closeButton, SIGNAL(close), SLOT(close()));
}

Aboutus::~Aboutus()
{
    delete ui;
}





void Aboutus::on_pushButton_clicked()
{

    accept();


}

