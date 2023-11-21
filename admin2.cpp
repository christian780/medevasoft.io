#include "admin2.h"
#include "ui_admin2.h"

Admin2::Admin2(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Admin2)
{
    ui->setupUi(this);

}

Admin2::~Admin2()
{
    delete ui;
}






