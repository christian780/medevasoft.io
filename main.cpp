#include "mainwindow.h"
#include <QApplication>
#include<new>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("./image/logo1.jpg"));
    MainWindow w;
    w.show();
    return a.exec();
}
