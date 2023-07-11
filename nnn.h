#ifndef NNN_H
#define NNN_H

#include <QWidget>
#include <QList>
#include <QMessageBox>
#include <QTimer>
#include "prokatadd.h"
#include "form1.h"
#include "kino.h"
#include "product.h"
#include "concretebuilder.h"
#include "director.h"
#include "passticket.h"

namespace Ui {
class nnn;
}

class nnn : public QWidget
{
    Q_OBJECT

public:
    explicit nnn(Form1*, kino*, QWidget *parent = nullptr);
    ~nnn();
    QList<product*> list; //список элементов (билетов)

signals:
    void z(); //сигнал, отслеживающий возвращение к главному меню

private slots:
    void back(); //функция возвращения к главному меню
    void buy(); //функциия, открывающая форму заполения данных о билете
    void addlist(QString film, QString sname, QString name, QString pl); // функция добавления элементов в список
    void pass(); //функция сдачи билета
    void fill_table(); //функция заполнения таблицы
    void passlist(QString, QString, QString, QString); //функция удаления из списка



private:
    prokatadd padd; //окно заполения данных для выдачи билеиа
    passticket pticket; //окно заполнения данных для возврата билета
    kino* Kino; //объект класса для работы со списком фильмов
    Form1* client; //объект класса для работы со списком клиентов
    Director director; //директор, для управления выбра метода строителя


    Ui::nnn *ui;
};

#endif // NNN_H
