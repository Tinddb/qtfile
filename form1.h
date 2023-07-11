#ifndef FORM1_H
#define FORM1_H

#include <QWidget>
#include <QMessageBox>
#include <QTimer>
#include <QTextStream>
#include <QFile>
#include "client.h"
#include "director.h"
#include "concretebuilder.h"
#include "product.h"


namespace Ui {
class Form1;
}

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = nullptr);
    ~Form1();
    QList<product*> mass; //список клиентов, элементы списка - результат работы строителя


signals:
    void cl(); //сигнал, подающийся при нажатии на клавишу назад, для возврата к главному меню


private slots:
    void back(); //функция возвращения назад
    void add(); //функция, отслеживающая нажатие на клавишу добавить
    void delete_client(); //функция удаления клиента по номер
    void search_client(); //функция поиска клиента
    void addlist(QString name, QString sname, QString pname, QString num, QString mail); //функция, добавляющая данные в список
    void fill_table(); //функция заполенения таблицы
    void check_search_button(); //функция проверки ввода поля для поиска
    void check_del_button(); //функция проверки ввода поля для удаления
    void load_file(); //функция загрузки данных из файла

private:
    Director director; //объект класса директор для управления строителем
    Client c; //окно для ввода данных о клиенте
    Ui::Form1 *ui;


};

#endif // FORM1_H
