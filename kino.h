#ifndef KINO_H
#define KINO_H

#include <QWidget>
#include <QMessageBox>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include "kinoadd.h"
#include "product.h"
#include "director.h"
#include "concretebuilder.h"


namespace Ui {
class kino;
}

class kino : public QWidget
{
    Q_OBJECT

public:
    explicit kino(QWidget *parent = nullptr);
    ~kino();

    QList<product*> mass; //список фильмов, элементы списка - результат работы строителя

public slots:
    void reset(); //функция обновления данных в таблице

signals:
    void cc(); //сигнал, подающийся при нажатии на клавишу назад, для возврата к главному меню

private slots:
    void back(); //функция возврата назад
    void add(); //функция, отслеживающая нажатию на клавишу добавить
    void addlist(QString, QString, QString, QString, QString); //функция, добавляющая данные в список
    void search_el(); //функция поиска фильма
    void del_el(); //функция удаления фильма
    void check_del_button(); // функция проверки ввода поля удаления
    void check_search_button(); //функция проверки ввода поля поиска
    void fill_table(); //функция заполнения таблицы
    void load_file(); //функция загрузки данных из файла

private:
    Director director; //объекта класса директор, управляющий строителем
    kinoadd ka; //окно для ввода данных о фильме
    Ui::kino *ui;
};

#endif // KINO_H
