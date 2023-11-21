#ifndef ADMIN2_H
#define ADMIN2_H

#include <QFrame>
#include <mainwindow.h>


namespace Ui {
class Admin2;
}

class Admin2 : public QFrame
{
    Q_OBJECT

public:
    explicit Admin2(QWidget *parent = nullptr);
    ~Admin2();





private:
    Ui::Admin2 *ui;



};

#endif // ADMIN2_H
