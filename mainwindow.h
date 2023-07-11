#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "kino.h"
#include "form1.h"
#include "nnn.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void choose(); //функция выбора в главном меню

private:
    kino *k; //окно для работы с фильмами
    Form1* form; //окно для работы с клиентами
    nnn* nn; //окно для работы с покупкой/сдачей билетов
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
