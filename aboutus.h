#ifndef ABOUTUS_H
#define ABOUTUS_H

#include <QDialog>

namespace Ui {
class Aboutus;
}

class Aboutus : public QDialog
{
    Q_OBJECT

public:
    explicit Aboutus(QWidget *parent = nullptr);
    ~Aboutus();
    Aboutus *abt;

private slots:

    void on_pushButton_clicked();

private:
    Ui::Aboutus *ui;
};

#endif // ABOUTUS_H
