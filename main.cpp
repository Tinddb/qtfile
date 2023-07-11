#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Главное меню");
    //w.setStyleSheet("background-color:red");
    w.show();
    return a.exec();
}
